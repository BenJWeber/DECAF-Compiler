// Benjamin Weber
// Lab 9
// 10/31/2022
// AST code from Dr Cooper, adapted by Ben Weber.
// 
#include<stdio.h>
#include<malloc.h>
#include "ast.h" 


// precondition: the node you want to create must be listed in AST_Tree_Element_Type in ast.h.
// postcondition: ASTnode address is returned which has  data segments set to starting values, and type given by input.
ASTnode *ASTCreateNode(enum AST_Tree_Element_Type mytype)
{
    ASTnode *p;
    if (mydebug) fprintf(stderr,"Creating AST Node \n");
    p=(ASTnode *)malloc(sizeof(ASTnode)); // get head data
    p->type=mytype; // set up the Element type
    p->S1=NULL;
    p->S2=NULL;  // det default values
    p->value=0;
    return(p);
}

// precondition: none
// postcondition: A space has been printed "howmany" times.
void PT(int howmany)
{
	 for(int i = 0; i < howmany; i++) {
        printf(" ");
     }

}

// precondition: type must be listed in AST_Decaf_Types
// postcondition: type is printed, or error if type is unknown.
void AST_Print_Type( enum AST_Decaf_Types t)
{
	switch (t) {

		case  A_Decaf_INT : printf(" INT ");
            break;
        case  A_Decaf_BOOL : printf(" BOOL ");
            break;
        case A_Decaf_STRING : printf(" STRING ");
            break;
        case A_Decaf_VOID : printf(" VOID ");
            break;
        default:  fprintf(stderr,"Unknown AST DECAF TYPE !!!\n");
	} // of switch


}// of AST_Print_Type


// precondition: level should be >= 0
// postcondition: Prints the program structure based on the AST given, with appropriate indentation
void ASTprint(int level,ASTnode *p)
{
   int i;
   if (p == NULL ) return;
   else
     { 
       PT(level); /*indent */
       
       switch (p->type) {
        
        case A_PROGRAM : printf("\n"); // start of program is implied so no need to print
                         ASTprint(level + 1, p->S1);
                         ASTprint(level + 1, p->S2);
                         break;
        
        case A_PACKAGE : printf("PACKAGE %s \n", p->name);
                         ASTprint(level + 1, p->S1);
                         ASTprint(level + 1, p->S2);
                         break;
        
        case A_EXTERN : printf("EXTERN FUNC %s ", p->name);
                        printf("(");
                        ASTprint(level, p->S1);
                        printf(")");
                        AST_Print_Type(p->A_Declared_Type);
                        printf("\n\n");
                        break;
        
        case A_ExternType : printf("externType ");
                            AST_Print_Type(p->A_Declared_Type);
                            break;

        case A_VARDEC :  printf("Variable ");
                         printf(" %s",p->name);
                         
                         if (p->S1 != NULL) // then it is an array
                         {
                             printf("[");
                             printf("%d", p->S1->value);
                             printf("]");
                         }
                         AST_Print_Type(p->A_Declared_Type);
                         
                         // has initial value
			 if (p->A_Declared_Type == A_Decaf_BOOL) {
                         	if (p->S2 != NULL) { 
                             		if (p->S2->value == 0) {
                                		printf(" = false");
                             		} 
                             		else  {
                                		printf(" = true");
                             		}
				}
			 }

			 if (p->A_Declared_Type == A_Decaf_INT) {
			 	if (p->S2 != NULL) {
			 		printf(" %d", p->S2->value);   
		   	 
				}
			 }

                         printf("\n"); 
                         break;
        
        case A_METHODIDENTIFIER : printf("Method Variable ");
                                  printf(" %s",p->name); 
                                  AST_Print_Type(p->A_Declared_Type);
                                  printf("\n"); 
                                  break;
        
        case A_METHODDEC :  
                            printf(" Method ");
                            printf("%s with type ",p->name);
                            AST_Print_Type(p->A_Declared_Type);
                     
                            /* print out the parameter list */
                     
                            if (p->S1 == NULL ) // no parameters
		                    {
                                PT(level+2); 
		                        printf (" (NONE) "); 
                            }
                            else
                            {   
                                PT(level+2);
                                printf( "( \n");
                                ASTprint(level+2, p->S1);
                                PT(level+2);
                                printf( ") ");
                            }
                            printf("\n");
                            ASTprint(level+2, p->S2); // print out the block
                            break;
        
        case A_PARAM :  printf("PARAMETER ");
                        if (p->operator == A_Decaf_INT)
                           printf (" INT ");
                      
                        if (p->operator == A_Decaf_BOOL)
                           printf (" VOID ");
                      
                        if (p->operator == A_Decaf_VOID)
                           printf (" BOOLEAN ");
                      
                        printf (" %s",p->name);
                      
                        if (p->value == -1 ) 
                           printf("[]");
                        printf("\n");                  
                       break;
        
        // A_EXPR handles all  operators
        case A_EXPR :  printf("EXPR ");
                       switch(p->operator) {
   			            case A_PLUS : printf(" + ");
                            break;
   			            
                        case A_MINUS: printf(" - ");
                            break;
                        
                        case A_DIVIDE: printf(" / ");
                            break;
                        
                        case A_UMINUS: printf(" - ");
                            break;
                        
                        case A_TIMES: printf(" * ");
                            break;

                        case A_MOD: printf(" % ");
                            break;
                        
                        case A_OR: printf(" || ");
                            break;
                        
                        case A_AND: printf(" && ");
                            break;
                        
                        case A_LEFTSHIFT: printf(" << ");
                            break;
                        
                        case A_RIGHTSHIFT: printf(" >> ");
                            break;
                        
                        case A_NOT: printf(" ! ");
                            break;
                        
                        case A_EQ:  printf(" == ");
                            break;
                        
                        case A_NEQ: printf(" != ");
                            break;
                        
                        case A_GT:  printf(" > ");
                            break;
                        
                        case A_LT:  printf(" < ");
                            break;
                        
                        case A_GEQ:  printf(" >= ");
                            break;
                        
                        case A_LEQ:  printf(" <= ");
                            break;
                        
                        default: printf("Unknown operator %d", p->operator);
                        }
                        
                        printf("\n");
                        
                        ASTprint(level+1, p->S1);
		                
                        if (p->operator != A_NOT)   // if operator is not A_NOT, print S2 
                           ASTprint(level+1, p->S2);
                        break;
        
        case A_BLOCK :  printf("BLOCK STATEMENT  \n");
                        ASTprint(level+1, p->S1);
                        ASTprint(level+2, p->S2);
                        printf("\n");
                        break;
        
        case A_BREAK : printf("BREAK STATEMENT \n");
                       printf("\n");
                       break;
        
        case A_RETURN : printf("RETURN STATEMENT \n");
                        ASTprint(level+1, p->S1); // do RETURN expression if any
                        printf("\n");
                        break;
        
        case A_WHILESTMT :  printf("WHILE STATEMENT \n");
                            ASTprint(level+1, p->S1);
                            ASTprint(level+2, p->S2);
                            break;
        
        case A_CONSTANT_INT :  printf("CONSTANT INTEGER %d\n",p->value);
                               ASTprint(level+1, p->S1);
                               break;
        
        case A_CONSTANT_BOOL : printf("CONSTANT BOOL ");
                               if (p->value == 1) {  // instead of printing 1, print true
                                   printf(" true\n");
                               }
                               
                               else {
                                   printf(" false\n"); // instead of printing 0(or anything else) print false
                               }

                               ASTprint(level+1, p->S1);
                               break;
        
        case A_CONSTANT_STRING : printf("CONSTANT STRING  %s\n ", p->name);
                                 ASTprint(level+1, p->S1);
                                 break;
        
        case A_METHODCALL : printf("METHOD CALL ");
                            printf("name: %s\n", p->name);
                            ASTprint(level+1, p->S1);
                            break;
        
        case A_METHODARG : printf("METHOD ARG \n");
                           ASTprint(level+1, p->S1);
                           break;
        
        case A_CONTINUE : printf("CONTINUE STATEMENT \n");
                          ASTprint(level+1, p->S1);
                          break;
        
        case A_ASSIGN : printf("ASSIGNMENT STATEMENT \n");
                        ASTprint(level+1, p->S1);
                        ASTprint(level+2, p->S2);
                        break;
        
        case A_LVALUE : printf("VARIABLE ");
                        printf(" %s\n", p->name);
                        ASTprint(level+1, p->S1);
                        break;
        
        case A_VAR_RVALUE : printf("VARIABLE ");
                            printf(" %s\n", p->name);
                            if (p->S1 != NULL) {
                               PT(level+1);
                               printf("[\n");
                               ASTprint(level+1, p->S1);
                               PT(level+1);
                               printf("]\n");
                            }
                            else {
                               ASTprint(level+1, p->S1);
                            }
                            break;
        
        case A_IFSTMT : printf("IF STATEMENT\n");
                        ASTprint(level+1, p->S1);
                        ASTprint(level+1, p->S2->S1); // if block is located in S2->S1
                        
                        // if this if statement has an else componenet
                        if (p->S2->S2 != NULL) {
                           PT(level+1); // add some spaces to look nice
                           printf("ELSE STATEMENT\n");
                           ASTprint(level+2, p->S2->S2); // else block is located in S2->S2
                        }
                        break;
        
        default: printf("unknown type in ASTprint\n");


       }
       ASTprint(level, p->next);
     }
}

// precondition: check_parameters should be called with two ASTnode pointers
// postcondition: returns 1 if the two parameter lists are equal in type and length, or 0 if the parameter lists are different.
int check_parameters(ASTnode *formal, ASTnode *actual) {
	if (formal == NULL && actual == NULL)
		return 1;
        if (formal->A_Declared_Type != actual->S1->A_Declared_Type)
		return 0;	
	return(check_parameters(formal->next, actual->next));
}
