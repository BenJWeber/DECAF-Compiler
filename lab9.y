%{
// Ben Weber
// Lab 9
// 10/31/2022 
// 


	/* begin specs */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "symtable.h"
#include "ast.h"
#include "emit.h"

// function prototypes for emit.c
extern void emit_gas(FILE *fp);


// file variables
FILE *fp;

// create space for filename with .s suffix
char filename_final[100];


// keep track of level of blocks we have seen
int LEVEL = 0;

// maintain offsets
int OFFSET = 0;
int GOFFSET;
int MAXOFFSET;

// AST Global Pointer
struct ASTnodetype *PROGRAM;

// from Lex
extern int linecount;

extern int debugsw;

// prints linecount along with error notification
void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s on line  %d\n", s, linecount);
}

// This prototype makes the type of yylex() explicit and clears a warning
int yylex();


%}

/*  defines the start symbol, what values come back from LEX and how the operators are associated  */
%start Program


%union {
   int value;
   char* string;
   struct ASTnodetype *astnode;
   enum AST_Decaf_Types asttype;
   enum AST_Operators operator;
}

%token T_PACKAGE T_EXTERN 
%token <string> T_ID
%token T_INTEGER T_FUNC 
%token T_INT
%token T_BOOL T_STRING T_VOID
%token T_ASSIGN T_BREAK T_BOOLTYPE
%token T_AND T_CHARCONSTANT T_CONTINUE
%token T_DOT T_ELSE
%token T_EQ T_FALSE T_FOR
%token T_GEQ T_GT T_IF T_LT
%token <value> T_INTCONSTANT 
%token T_INTTYPE T_LEFTSHIFT
%token T_LEQ T_NEQ T_NULL
%token T_OR T_RETURN T_RIGHTSHIFT
%token <string> T_STRINGCONSTANT 
%token T_STRINGTYPE T_TRUE
%token T_VAR T_WHILE

%type <astnode> Externs ExternDefn ExternTypeList ExternTypeList1 FieldDecl FieldDecls 
%type <astnode> ArrayType MethodDecl MethodDecls IdTypeList IdTypeList1 Block
%type <astnode> VarDecl VarDecls MethodCall MethodArgList MethodArgList1 MethodArg
%type <asttype> MethodType Type ExternType
%type <astnode> Constant BoolConstant Statement Statements
%type <operator> Multop Addop Relop
%type <astnode> Factor Expr Term Simpleexpression Additiveexpression
%type <astnode> Assign Lvalue

%%	/* end specs, begin rules */
Program : Externs T_PACKAGE T_ID '{' FieldDecls MethodDecls '}'
            { PROGRAM = ASTCreateNode(A_PROGRAM);
              PROGRAM->S1 = $1;
              PROGRAM->S2 = ASTCreateNode(A_PACKAGE);
              PROGRAM->S2->name = $3;
              PROGRAM->S2->S1 = $5; 
              PROGRAM->S2->S2 = $6;
	      PROGRAM->S2->symbol = Insert($3, A_Decaf_VOID, ID_Sub_Type_Package , LEVEL, 0, 0, NULL);
            }
        ;

Externs : /*empty*/ 
            {$$ = NULL;}
        | ExternDefn Externs
            {$1->next = $2;}
	    ;

ExternDefn : T_EXTERN T_FUNC T_ID '(' ExternTypeList ')' MethodType ';'
             {
              	if (Search($3,LEVEL,0) != NULL) {
	         yyerror("Symbol already defined");
		 yyerror($3);
		 exit(1);
		}
	      	$$ = ASTCreateNode(A_EXTERN);
              	$$->name = $3;
              	$$->A_Declared_Type = $7;
              	$$->S1 = $5;
		$$->symbol=Insert($3, $7, ID_Sub_Type_ExternMethod, LEVEL, 0, 0, $5);
		}
           ;

ExternTypeList : /*empty*/  {$$ = NULL;}
	       | ExternTypeList1 {$$ = $1;}
	       ;

ExternTypeList1 : ExternType
                    {
                     $$ = ASTCreateNode(A_ExternType);
                     $$->A_Declared_Type = $1;
                    }
		        | ExternType ',' ExternTypeList1
                    {
                     $$ = ASTCreateNode(A_ExternType);
                     $$->A_Declared_Type = $1;
                     $$->next = $3;
                    }
                ;

FieldDecls : /*empty*/  {$$ = NULL;}
	       | FieldDecl FieldDecls
	         { $$ = $1;
               $$->next = $2;
             }
           ;

FieldDecl  : T_VAR T_ID Type ';'  
            {
		if (Search($2, LEVEL, 0) != NULL) {
		   yyerror("Field already defined");
		   yyerror($2);
		   exit(1);
		}
		$$ = ASTCreateNode(A_VARDEC);
             	$$->name = $2;
             	$$->A_Declared_Type = $3;
		$$->symbol = Insert($2, $3, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		OFFSET++;		
            }
           | T_VAR T_ID Type T_ASSIGN Constant ';' 
            {
		if (Search($2, LEVEL, 0) != NULL) {
		   yyerror("Field already defined");
		   yyerror($2);
		   exit(1);
		}
		$$ = ASTCreateNode(A_VARDEC);
             	$$->name = $2;
             	$$->A_Declared_Type = $3;
             	$$->S2 = $5;
                $$->symbol = Insert($2, $3, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		OFFSET++;
	    }
           | T_VAR T_ID ArrayType ';'
            {
		if (Search($2, LEVEL, 0) != NULL) {
		   yyerror("Field already defined");
		   yyerror($2);
		   exit(1);
		}
		$$ = ASTCreateNode(A_VARDEC);
             	$$->name = $2;
             	$$->S1 = $3;
             	$$->A_Declared_Type = $3->A_Declared_Type;
                $$->symbol = Insert($2, $$->A_Declared_Type, ID_Sub_Type_Array, LEVEL, $$->S1->value, OFFSET, NULL);
		OFFSET += $$->S1->value;
	    }
           ;

MethodDecls : /*empty*/ {$$ = NULL;}
	        | MethodDecl MethodDecls
              {$$ = $1;
              $$->next = $2;}
	        ;

MethodDecl  : T_FUNC T_ID { GOFFSET = OFFSET; OFFSET = 0; MAXOFFSET = OFFSET;} '(' IdTypeList ')' MethodType
	      { if (Search($2, LEVEL, 0) != NULL) {
			yyerror("Method named already defined");
			yyerror($2);
			exit(1);
		}
		
	        Insert($2, $7, ID_Sub_Type_Method, LEVEL, 0, 0, $5);
	      
	      } Block
	      
	      {
	       $$ = ASTCreateNode(A_METHODDEC);
               $$->name = $2;
               $$->A_Declared_Type = $7;
               $$->S1 = $5;
               $$->S2 = $9;
	       $$->symbol = Search($2, LEVEL, 0);
	       $$->size = MAXOFFSET;
	       $$->symbol->mysize = MAXOFFSET;
	       OFFSET = GOFFSET;
	                      
              }
            ;

IdTypeList  : /*empty*/ {$$ = NULL;}
	    | IdTypeList1 {$$ = $1;}
	    ;

IdTypeList1 : T_ID Type 
	      { if (Search($1, LEVEL + 1, 0) != NULL) {
			yyerror("Duplicate method arg name");
			yyerror($1);
			exit(1);
		} 
		
	      	$$ = ASTCreateNode(A_METHODIDENTIFIER);
               	$$->name = $1;
               	$$->A_Declared_Type = $2;
		$$->symbol = Insert($1, $2, ID_Sub_Type_Scalar, LEVEL + 1, 1, OFFSET, NULL);
		OFFSET++; 
              }
            | T_ID Type ',' IdTypeList1
	       { 
	        if (Search($1, LEVEL + 1, 0) != NULL) {
			yyerror("Duplicate method arg name");
			yyerror($1);
			exit(1);
		} 
		$$ = ASTCreateNode(A_METHODIDENTIFIER);
               	$$->name = $1;
               	$$->A_Declared_Type = $2;
               	$$->next = $4;
		$$->symbol = Insert($1, $2, ID_Sub_Type_Scalar, LEVEL + 1, 1, OFFSET, NULL);
		OFFSET++; 
               }
            ;

Block : '{' 
         { LEVEL++; }
	 VarDecls Statements '}'
         {$$ = ASTCreateNode(A_BLOCK);
          $$->S1 = $3;
          $$->S2 = $4;
	  // at end of block, clear local variables and reduce offset and level accordingly
	  if (debugsw == 1) {
		Display();
	  }
	  
	  if (OFFSET > MAXOFFSET) MAXOFFSET = OFFSET;
	  OFFSET -= Delete(LEVEL);	
	  LEVEL--;
         }
      ;

VarDecls : /*empty*/ {$$ = NULL;}
	     | VarDecl VarDecls
            {$$ = $1;
             $$->next = $2;
            }
	     ;

VarDecl : T_VAR T_ID Type ';'
          {
 	if (Search($2, LEVEL, 0) != NULL) {
	   yyerror("Variable already defined at this level");
	   yyerror($2);
	   exit(1);
	}
	   $$ = ASTCreateNode(A_VARDEC);
           $$->name = $2;
           $$->A_Declared_Type = $3;
	   $$->symbol = Insert($2, $3, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
	   OFFSET++;
	   }
	 | T_VAR T_ID ArrayType ';'
          {
	   if (Search($2, LEVEL, 0) != NULL) {
	      yyerror("Array already defined at this level");
	      yyerror($2);
	      exit(1);
	   }
	   $$ = ASTCreateNode(A_VARDEC);
           $$->name = $2;
           $$->S1 = $3;
           $$->A_Declared_Type = $$->S1->A_Declared_Type; 
           $$->symbol = Insert($2, $$->A_Declared_Type, ID_Sub_Type_Array, LEVEL, $$->S1->value, OFFSET, NULL);
	   OFFSET += $$->S1->value; 
	   }
        ;

Statements : /*empty*/ {$$ = NULL;}
	   | Statement Statements
	     {$$ = $1;
          $$->next = $2;
         }
       ;

Statement : T_BREAK ';'
            {$$ = ASTCreateNode(A_BREAK);
            }
          | Block {$$ = $1;}
     	  | Assign ';' {$$ = $1;}
          | MethodCall ';' {$$ = $1;}
          | T_IF '(' Expr ')' Block
            {$$ = ASTCreateNode(A_IFSTMT);
             $$->S1 = $3;
             $$->S2 = ASTCreateNode(A_IFSTMT);
             $$->S2->S1 = $5;
            }
          | T_IF '(' Expr ')' Block T_ELSE Block
            {$$ = ASTCreateNode(A_IFSTMT);
             $$->S1 = $3;
             $$->S2 = ASTCreateNode(A_IFSTMT);
             $$->S2->S1 = $5;
             $$->S2->S2 = $7;
            }
          | T_WHILE '(' Expr ')' Block
            {$$ = ASTCreateNode(A_WHILESTMT);
             $$->S1 = $3;
             $$->S2 = $5;
            }
          | T_RETURN ';'
            {$$ = ASTCreateNode(A_RETURN);
            }
          | T_RETURN '(' ')' ';'
            {$$ = ASTCreateNode(A_RETURN);
            } 
          | T_RETURN '(' Expr ')' ';'
            {$$ = ASTCreateNode(A_RETURN);
             $$->S1 = $3;
            } 
          | T_CONTINUE ';' 
            {$$ = ASTCreateNode(A_CONTINUE);
            }
          ;


Assign : Lvalue T_ASSIGN Expr
         {
	  if ($1->A_Declared_Type != $3->A_Declared_Type) {
		yyerror("type mismatch on assignment ");
		exit(1);
	  }

	  $$ = ASTCreateNode(A_ASSIGN);
          $$->S1 = $1;
          $$->S2 = $3;
	  $$->name = TEMP_CREATE();
	  $$->symbol = Insert($$->name, $$->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
	  OFFSET++; 
         }
       ;

Lvalue : T_ID
         { 
	  struct SymbTab *p;
	  p = Search($1, LEVEL, 1);
	  if (p == NULL)
	     { yyerror("Symbol on LVALUE not defined");
	       yyerror($1);
	       exit(1);
	     }
	  if (p->SubType != ID_Sub_Type_Scalar)
	     { yyerror($1);
	       yyerror(" needs to be a scalar, wrong subtype");
	       exit(1);
	     }
	
	 $$ = ASTCreateNode(A_LVALUE);
         $$->name = $1;
	 $$->symbol = p;
	 $$->A_Declared_Type = p->Type;
         }
       | T_ID '[' Expr ']'
         {
	  struct SymbTab *p;
	  p = Search($1, LEVEL, 1);
	  if (p == NULL)
	     { yyerror("Symbol on LVALUE not defined");
	       yyerror($1);
	       exit(1);
	     }
	  if (p->SubType != ID_Sub_Type_Array)
	     { yyerror($1);
	       yyerror(" needs to be an array, wrong subtype");
	       exit(1);
	     }
	

	  $$ = ASTCreateNode(A_LVALUE);
          $$->name = $1;
          $$->S1 = $3;
	  $$->A_Declared_Type = p->Type;
         }
       ;


MethodCall : T_ID '(' MethodArgList ')'
             {	
	  struct SymbTab *p;
	  p = Search($1, LEVEL, 1);
	  if (p == NULL)
	     { yyerror("Symbol not defined");
	       yyerror($1);
	       exit(1);
	     }
	  if (p->SubType != ID_Sub_Type_ExternMethod && p->SubType != ID_Sub_Type_Method) {
	        yyerror($1);
	       yyerror(" needs to be a method, wrong subtype");
	       exit(1);
	     }
		
	     if (check_parameters(p->fparms, $3) == 0) {
		yyerror("Formal and actual parameters do not match");
		yyerror($1);
		exit(1);
	     }
	
	      $$ = ASTCreateNode(A_METHODCALL);
              $$->name = $1;
              $$->S1 = $3;
	      $$->symbol = p;
	      $$->A_Declared_Type = p->Type;
             }
	       ;

MethodArgList : /*empty*/ {$$ = NULL;}
	          | MethodArgList1
                {$$ = $1;}
	          ;

MethodArgList1 : MethodArg
                 {// MethodArg node is handled here instead of in the MethodArg rule like the videos because my rules were set up differently for some reason
		  			// Instead of getting the type from Expr immediately, we get it after plumbing S1
		  			$$ = ASTCreateNode(A_METHODARG);
        			$$->S1 = $1;
		  			$$->A_Declared_Type = $$->S1->A_Declared_Type;
		  			$$->name = TEMP_CREATE();
	        		$$->symbol = Insert($$->name, $$->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		  			OFFSET++;
                 }
               | MethodArg ',' MethodArgList1
                 {// MethodArg node is handled here instead of in the MethodArg rule like the videos because my rules were set up differently for some reason
                  // Instead of getting the type from Expr immediately, we get it after plumbing S1

		  $$ = ASTCreateNode(A_METHODARG);
                  $$->S1 = $1;
                  $$->next = $3;
                  $$->A_Declared_Type = $$->S1->A_Declared_Type;
	          $$->name = TEMP_CREATE();
		  $$->symbol = Insert($$->name, $$->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		  OFFSET++;
                 }
	         ;

MethodArg : Expr 
	    {
	     $$ = $1;
	    }
	    | T_STRINGCONSTANT
            {	$$ = ASTCreateNode(A_CONSTANT_STRING);
             	$$->name = $1;
	     		$$->A_Declared_Type = A_Decaf_STRING;
            }
          ;


Expr : Simpleexpression {$$ = $1;}
     

Simpleexpression : Additiveexpression  {$$ = $1;}
		   | Simpleexpression Relop Additiveexpression
		   {
		    if ($1->A_Declared_Type != $3->A_Declared_Type)
			{ yyerror("both sides need to be of the same type");
			  exit(1);
			}

		    $$ = ASTCreateNode(A_EXPR);
                    $$->S1 = $1;
                    $$->operator = $2;
		    $$->A_Declared_Type = A_Decaf_BOOL;
                    $$->S2 = $3;
		    $$->name = TEMP_CREATE();
                    $$->symbol = Insert($$->name, $$->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		    OFFSET++;
                   }
                 ;

Relop : T_LEQ {$$ = A_LEQ;}
      | T_LT  {$$ = A_LT;}
      | T_GT  {$$ = A_GT;}
      | T_GEQ {$$ = A_GEQ;}
      | T_EQ  {$$ = A_EQ;}
      | T_NEQ {$$ = A_NEQ;}
      ;

Additiveexpression : Term  {$$ = $1;}
		     | Additiveexpression Addop Term
               	     { // if the two parts are not integers, exit with error
		      if ( ($1->A_Declared_Type != $3->A_Declared_Type) || ($1->A_Declared_Type != A_Decaf_INT)) {
			yyerror("addition and subtraction only allowed for integers");
		        exit(1);
		     }
		
		      $$ = ASTCreateNode(A_EXPR);
                      $$->S1 = $1;
                      $$->operator = $2;
                      $$->S2 = $3;
		      $$->A_Declared_Type;
		      $$->name = TEMP_CREATE();
                      $$->symbol = Insert($$->name, $$->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
		      OFFSET++;
                     }
                   ;

Addop : '+' {$$ = A_PLUS;}
      | '-' {$$ = A_MINUS;}
      ;

Term : Factor  {$$ = $1;}
     | Term Multop Factor
       {
	if ($1->A_Declared_Type != $3->A_Declared_Type)
	{ yyerror("type mismatch");
	  exit(1);
        } 
        // if booleans are used in integer expression, exit with error
	if ($1->A_Declared_Type == A_Decaf_BOOL) {
		if (($2 == A_TIMES) || ($2 == A_DIVIDE) || ($2 == A_MOD)) {
			yyerror("cannot use boolean in arithmetic operation");
			exit(1);
		}
	}
	// if integeres are used in a boolean expression, exit with error
	if ($1->A_Declared_Type == A_Decaf_INT) {
		if (($2 == A_AND) || ($2 == A_OR) || ($2 == A_LEFTSHIFT) || ($2 == A_RIGHTSHIFT)) {
			yyerror("cannot use integer in boolean operation");
			exit(1);
		}
	}

	$$ = ASTCreateNode(A_EXPR);
        $$->S1 = $1;
        $$->operator = $2;
        $$->S2 = $3;
	$$->A_Declared_Type = $1->A_Declared_Type;
	$$->name = TEMP_CREATE();
        $$->symbol = Insert($$->name, $$->A_Declared_Type, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
	OFFSET++;
       }
     ;

Multop : '*' {$$ = A_TIMES;}
       | '/' {$$ = A_DIVIDE;}
       | '%' {$$ = A_MOD;}
       | T_AND {$$ = A_AND;}
       | T_OR  {$$ = A_OR;}
       | T_LEFTSHIFT  {$$ = A_LEFTSHIFT;}
       | T_RIGHTSHIFT  {$$ = A_RIGHTSHIFT;}
       ;

Factor : T_ID
          {	
	  struct SymbTab *p;
	  p = Search($1, LEVEL, 1);
	  if (p == NULL)
	     { yyerror("Symbol on RVALUE not defined");
	       yyerror($1);
	       exit(1);
	     }
	  if (p->SubType != ID_Sub_Type_Scalar)
	     { yyerror($1);
	       yyerror(" needs to be a scalar, wrong subtype");
	       exit(1);
	     }
	
	   $$ = ASTCreateNode(A_VAR_RVALUE);
           $$->name = $1;
	   $$->symbol = p;
	   $$->A_Declared_Type = p->Type;
          }
       | MethodCall {$$ = $1;}
       | T_ID '[' Expr ']'
          {
	  struct SymbTab *p;
	  p = Search($1, LEVEL, 1);
	  if (p == NULL)
	     { yyerror("Symbol on RVALUE not defined");
	       yyerror($1);
	       exit(1);
	     }
	  if (p->SubType != ID_Sub_Type_Array)
	     { yyerror($1);
	       yyerror(" needs to be a scalar, wrong subtype");
	       exit(1);
	     }

	   $$ = ASTCreateNode(A_VAR_RVALUE);
           $$->name = $1;
           $$->S1 = $3;
	   $$->symbol = p;
	   $$->A_Declared_Type = p->Type;
          }
       | Constant  {$$ = $1;}
       | '(' Expr ')'  {$$ = $2;}
       | '!' Factor
         {
	  if ($2->A_Declared_Type != A_Decaf_BOOL)
		{ yyerror("type mismatch, expecting a boolean");
		  exit(1);
		}

	  	$$ = ASTCreateNode(A_EXPR);
        $$->operator = A_NOT;
      	$$->S1 = $2;
	  	$$->A_Declared_Type = A_Decaf_BOOL;
	  	$$->name = TEMP_CREATE();
  	 	$$->symbol = Insert($$->name, A_Decaf_BOOL, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
	 	OFFSET++;
    	}
       | '-' Factor
        {// if factor is not an integer, exit with error
	  		if ($2->A_Declared_Type != A_Decaf_INT)
			{
		 		yyerror("type mismatch, expecting an integer");
		 		exit(1);
			}

	  		$$ = ASTCreateNode(A_EXPR);
        	$$->operator = A_UMINUS;
        	$$->S1 = $2;
	  		$$->A_Declared_Type = A_Decaf_INT;
        	$$->name = TEMP_CREATE();
	  		$$->symbol = Insert($$->name, A_Decaf_INT, ID_Sub_Type_Scalar, LEVEL, 1, OFFSET, NULL);
	  		OFFSET++;
        }       
       	;


ExternType : T_STRING {$$ = A_Decaf_STRING;}
	       | Type
	       ;

Type : T_INT    {$$ = A_Decaf_INT;}
     | T_BOOL   {$$ = A_Decaf_BOOL;}
     ;

MethodType : T_VOID {$$ = A_Decaf_VOID;}
	       | Type   {$$ = $1;}
           ; 

BoolConstant : T_TRUE
               {$$ = ASTCreateNode(A_CONSTANT_BOOL);
                $$->value = 1;
		$$->A_Declared_Type = A_Decaf_BOOL;
               }
	         | T_FALSE
               {$$ = ASTCreateNode(A_CONSTANT_BOOL);
                $$->value = 0;
		$$->A_Declared_Type = A_Decaf_BOOL;
               }
             ;

ArrayType : '[' T_INTCONSTANT ']' Type
	         {$$ = ASTCreateNode(A_ARRAYTYPE);
              $$->value = $2;
              $$->A_Declared_Type = $4;
             }
          ;

Constant : T_INTCONSTANT
           {$$ = ASTCreateNode(A_CONSTANT_INT);
            $$->value = $1;
	    	$$->A_Declared_Type = A_Decaf_INT;
           }
	   
	   	|	 BoolConstant {$$ = $1;}
           ;

%%	/* end of rules, start of program */

// added explicit type return to clear warning
int main(int argc, char* argv[])
{ 
	// create filename variable
	char* filename = (char *) malloc(100);
	char default_name = 'a';
	strncat(filename, &default_name, 1);

    // parse arguments
    for(int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0)
            debugsw = 1;
        if (strcmp(argv[i], "-o") == 0) {
            if (argv[i+1] == NULL) {
                printf("-o flag must be followed by a filename.\n");
                exit(1);
            }
            
            filename = argv[i+1];
        }
    }
	
	// append filename with .s suffix
	strcpy(filename_final, filename);
	char period = '.';
	char extension = 's';
	strncat(filename_final, &period, 1);
	strncat(filename_final, &extension, 1);

    yyparse();

	if (debugsw == 1) {
    	Display();
    	printf("Parsing complete!\n");
    	ASTprint(0,PROGRAM);
    	printf("\nDone printing.\n");
	}

	fp = fopen(filename_final, "w");
	
	emit_gas(fp);

    return 0;
}
