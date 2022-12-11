/* Ben Weber
   Lab 9
   10/31/2022
   
*/

%{

// This variable controls debug output for both lex and yacc (0 = debug off, 1 = debug on)
int debugsw = 0;

int linecount = 1;

// prototype for hex to integer function
int htoi (char*);

#include "ast.h"
#include "y.tab.h"
%}


%%
"package"		{return (T_PACKAGE);}
"extern"		{return (T_EXTERN);}
"func"			{return (T_FUNC);}
"void"			{return (T_VOID);}
"int"			{return (T_INT);}
"string"		{return (T_STRING);}
"bool"			{return (T_BOOL);}
"&&"			{return (T_AND);}
"break"			{return (T_BREAK);}
"continue"		{return (T_CONTINUE);}
\.			    {return (T_DOT);}
"else"			{return (T_ELSE);}
"=="			{return (T_EQ);}
"false"			{return (T_FALSE);}
"for"			{return (T_FOR);}
">="			{return (T_GEQ);}
">"			    {return (T_GT);}
"if"			{return (T_IF);}
int_lit			{return (T_INTCONSTANT);}
"<<"			{return (T_LEFTSHIFT);}
"<="			{return (T_LEQ);}
"!="			{return (T_NEQ);}
"null"			{return (T_NULL);}
"||"			{return (T_OR);}
"return"		{return (T_RETURN);}
">>"			{return (T_RIGHTSHIFT);}
"true"			{return (T_TRUE);}
"var"			{return (T_VAR);}
"while"			{return (T_WHILE);}
"<"	            {return (T_LT);}
"="             {return (T_ASSIGN);}

\'.\'		{yylval.value=yytext[1]; return (T_CHARCONSTANT);}

\".*\"		{if (debugsw) fprintf(stderr, "string constant found\n"); yylval.string=strdup(yytext); return (T_STRINGCONSTANT);}

[A-Za-z][A-Za-zZ0-9_]*	{if (debugsw) fprintf(stderr,"Letter found\n"); yylval.string=strdup(yytext); return(T_ID);}

[0-9][0-9]*	{if (debugsw) fprintf(stderr,"Digit found\n"); yylval.value=atoi((const char *)yytext); return(T_INTCONSTANT);}

0x[A-Fa-f0-9]+   {yylval.value=htoi((char* ) yytext); return (T_INTCONSTANT);}

\/\/.*		{ /* this is a comment line for double slash  Return nothing, keep going */ }

[ \t]		{if (debugsw) fprintf(stderr,"Whitespace found\n");}

[!;()\-+*/%{},\[\]]	{ if (debugsw) fprintf(stderr,"return a token %c\n",*yytext); /* added () so lex will make a token when it sees parentheses */ return (*yytext);}

\n		{ if (debugsw) fprintf(stderr,"carriage return %c\n",*yytext); linecount++;}
%%


//precondition: input is a string of characters representing a hexadecimal number, i.e: matching the regex 0x[A-Fa-f0-9]+
//postcondition: returns an integer representation of the hex input
int htoi(char* hex) {
   char* strtol_ptr;
   int result;
   if (hex != NULL) {
      result = strtol(hex, &strtol_ptr, 0);
   }
   return result;
}

int yywrap(void)
{ return 1;}
