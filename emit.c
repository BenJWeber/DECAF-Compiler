// emit.c
// translating Decaf to GAS
// Ben Weber
// 11/6/2022
// 

#include <string.h>
#include "emit.h"
#include "ast.h"
#include "symtable.h"

// internal prototypes
void Emit_Globals(ASTnode *p, FILE *fp);
void Emit_AST(ASTnode *p, FILE *fp);
void Emit_Method_Decl(ASTnode *p, FILE *fp);
void Emit_Method_Call(ASTnode *p, FILE *fp);
void Emit_Return(ASTnode *p, FILE *fp);
void Emit_string(ASTnode* p, FILE* fp);
void Emit_Expr(ASTnode* p, FILE* fp);
void Emit_Extern_Method_Call(ASTnode* p, FILE* fp);
void Emit_Assign(ASTnode* p, FILE* fp);
void Emit_Ident(ASTnode* p, FILE* fp);
void emit_if(ASTnode* p, FILE* fp);
char* CreateLabel();
void emit_while(ASTnode* p, FILE* fp);


// external prototypes
struct ASTnodetype *PROGRAM;

// globals
int LCOUNT = 0;

struct LabelList {
    char* label;
    struct LabelList* next;
};

struct LabelList* GOBACK = NULL;
struct LabelList* GETOUT = NULL;

struct LabelList* PushLabel(char* L, struct LabelList* target) {
    struct LabelList* p; 
    p = (struct LabelList * ) (malloc (sizeof (struct LabelList))); 
    p->label = L;
    p->next = target;
    return p;
}

// PRE: none
// POST: returns an integer 
char* CreateLabel() {
    char s[100];
	sprintf(s, "L%d", LCOUNT);
	LCOUNT++;
	return(strdup(s));
}



// helper function
// PRE: FP and various strings to print, or NULL
// POST: output properly formatted assembly to FP
void emit(FILE* fp, char* label, char* action, char* comment) {
    
    // do strcmp's now to reduce complexity of later if statements.
    // i.e. we want 0 (false) if strings are empty, and 1 (true) if strings are not empty.
    // which requires the opposite of the return value of these strcmp's.
    // this will make the many if statements easier to write/understand
    int label_exists = strcmp(label, "");
    int action_exists = strcmp(action, "");
    int comment_exists = strcmp(comment, "");
    
    if (label_exists != 0)
        label_exists = 1;
    
    if (action_exists != 0)
        action_exists = 1;

    if (comment_exists != 0)
        comment_exists = 1;

    

    // no label, no action, no comment
    if (label_exists == 0 && action_exists == 0 && comment_exists == 0 ) {
        fprintf(fp, "\n");
    }

    // yes label, no action, no comment
    if (label_exists && action_exists == 0 && comment_exists == 0) {
        fprintf(fp, "%s:\n", label);
    }

    // yes label, yes action, no comment
    if (label_exists && action_exists && comment_exists == 0) {
        fprintf(fp, "%s:\t%s\n", label, action);
    }

    // yes label, yes action, yes comment
    if (label_exists && action_exists && comment_exists) {
        fprintf(fp, "%s:\t%s\t# %s\n", label, action, comment);
    }

    // no label, yes action, no comment
    if (label_exists == 0 && action_exists && comment_exists == 0) {
        fprintf(fp, "\t%s\n", action);
    }

    // no label, yes action, yes comment
    if (label_exists == 0 && action_exists && comment_exists) {
        fprintf(fp, "\t%s\t# %s\n", action, comment);
    }

    // no label, no action, yes comment
    if (label_exists == 0 && action_exists == 0 && comment_exists) {
        fprintf(fp, "# %s\n", comment);
    }

    // yes label, no action, yes comment
    if (label_exists && action_exists == 0 && comment_exists) {
        fprintf(fp, "%s:\t# %s\n", label, comment);
    }

}

// PRE: fp must exist
// POST: GAS boiler plate will be printed
void emit_gas(FILE* fp) {
    
    fprintf(fp, "#\tPackage: %s\n", PROGRAM->S2->name);
    fprintf(fp, "\t.section \t.rodata \t# start of the RODATA section, strings first\n");
    fprintf(fp, "\npercentD:\t.string \"%%d\" \t# Always needed for print int\n");
    fprintf(fp, "\n# Next lines are all the strings in the program\n\n");
    Emit_string(PROGRAM, fp);
    fprintf(fp, "\n# End of string list\n");
    fprintf(fp, "\n\t\t.data \t# Start of the data section for variables\n\n");
    fprintf(fp, "\n\t\t.comm _SCANFHOLD,8,8\n");
    Emit_Globals(PROGRAM->S2->S1, fp);
    fprintf(fp, "\n%s\n", "# End of data section for variables");
    fprintf(fp, "\n%s\t%s\n", ".text", "# start of code segment");\
    Emit_AST(PROGRAM, fp);

}

void Emit_AST(ASTnode* p, FILE* fp) {
    if (p == NULL) return;

    switch (p->type) {
        case A_PROGRAM : 
            Emit_AST(p->S1, fp);
            Emit_AST(p->S2, fp);
            Emit_AST(p->next, fp);        
            break;
        
        case A_PACKAGE : 
            Emit_AST(p->S1, fp);
            Emit_AST(p->S2, fp);
            Emit_AST(p->next, fp);             
            break;
        
        case A_EXTERN : break;
        
        case A_ExternType : break;

        case A_VARDEC :  break;
        
        case A_METHODIDENTIFIER : break;
        
        case A_METHODDEC :  Emit_Method_Decl(p,fp);
                            Emit_AST(p->next,fp);
                            break;
        
        case A_PARAM :  break;
        
        case A_EXPR :  break;
        
        case A_BLOCK :  
            Emit_AST(p->S2, fp);
            Emit_AST(p->next, fp);
            break;
        
        case A_BREAK : break;
        
        case A_RETURN : 
            Emit_Return(p,fp);
            Emit_AST(p->next, fp);
            break;
        
        case A_WHILESTMT :  
            emit_while(p, fp);
            Emit_AST(p->next, fp);
            break;
        
        case A_CONSTANT_INT :  break;
        
        case A_CONSTANT_BOOL : break;
        
        case A_CONSTANT_STRING : break;
        
        case A_METHODCALL : 
            Emit_Method_Call(p, fp);
            Emit_AST(p->next, fp);
            break;
        
        case A_METHODARG : break;
        
        case A_CONTINUE : break;
        
        case A_ASSIGN : 
            Emit_Assign(p, fp);
            Emit_AST(p->next, fp);
            break;
        
        case A_LVALUE : break;
        
        case A_VAR_RVALUE : break;
        
        case A_IFSTMT : 
            emit_if(p, fp);
            Emit_AST(p->next, fp);
            break;
        
        default: printf("WARNING WARNING Emit_AST should never be here!\n");
    }        
}

void Emit_Method_Decl(ASTnode* p, FILE *fp) {
    char s[100];

    fprintf(fp, "\t.globl %s \n",p->name);
    fprintf(fp, "\t.type %s, @function \n",p->name);
    emit(fp, p->name,"", "Start of Function");
    fprintf(fp, "\n");
    fprintf(fp,"\t.cfi_startproc\t# STANDARD FUNCTION HEADER FOR GAS\n");
    fprintf(fp, "\tpushq %rbp # STANDARD FUNCTION HEADER FOR GAS\n");
    fprintf(fp,"\t.cfi_def_cfa_offset 16\t# STANDARD FUNCTION HEADER FOR GAS\n");
    fprintf(fp,"\t.cfi_offset 6, -16\t# STANDARD FUNCTION HEADER FOR GAS\n");
    fprintf(fp, "\tmovq %rsp, %rbp\t# STANDARD FUNCTION HEADER FOR GAS\n");
    fprintf(fp, "\t.cfi_def_cfa_register 6\t# STANDARD FUNCITON HEADER FOR GAS\n");

    // generate body of method

    fprintf(fp, "\n");
    fprintf(fp, "\n");

    // carve out space on stack
    sprintf(s, "subq $%d, %%rsp", p->symbol->mysize*WSIZE);
    emit(fp,"",s,"Carve out stack for method");
    fprintf(fp, "\n");

    Emit_AST(p->S2, fp);    // this does the body of the method


    // implicit return
    Emit_Return(NULL, fp);

}

// PRE: PTR to ASTnode that is in the expression class
//          including constants and method calls
// POST: GAS code that sets %rax to the evaluation of the espression
void Emit_Expr(ASTnode* p, FILE* fp) {

    // we should never get NULL here due to preconditon
    char s[100]; // holder to make dynamic commands

    // base cases
    switch(p->type) {
        case A_CONSTANT_INT:
        case A_CONSTANT_BOOL:
            sprintf(s, "mov $%d, %%rax", p->value);
            emit(fp, "", s, "EXPR load constant");
            return;
            break;
        case A_METHODCALL:
            Emit_Method_Call(p, fp);
            return; // %rax is set, so just return
            break;

        case A_VAR_RVALUE:
            Emit_Ident(p, fp); // RAX has memory address
            emit(fp, "", "mov (%rax), %rax", "expression is the identifier");
            return;
            break;
        case A_IFSTMT:
            emit_if(p, fp);
            Emit_AST(p->next, fp);
            return;
            break;
        
        // TODO: base cases missing here
        default: break; // fall through to the recursive case

    }


    Emit_Expr(p->S1, fp); // LHS
    sprintf(s,"mov %rax, %d(%rsp)",p->symbol->offset*WSIZE);
    emit(fp,"",s,"Store expresion LHS in stack");

    if (p->S2 != NULL) {
        Emit_Expr(p->S2,fp);
        emit(fp,"","mov %rax, %rbx","RHS of Expression");
    }   
    sprintf(s,"mov %d(%rsp), %rax",p->symbol->offset*WSIZE);
    emit(fp,"",s,"pull expresion LHS out of stack");

    switch(p->operator) {
        case A_PLUS:
            emit(fp,"","add %rbx, %rax", "expression add");
            break;

        case A_MINUS:
            emit(fp, "", "sub %rbx, %rax", "expression subtract");
            break;
        
        case A_TIMES:
            emit(fp, "", "mul %rbx", "expression multiply");
            break;
        
        case A_DIVIDE:
            emit(fp, "", "mov $0, %rdx", "clear rdx because div uses rdx and rax");
            emit(fp, "", "div %rbx", "expression divide");
            break;

        case A_UMINUS:
            sprintf(s, "mov $-%d, %rax", p->S1->value);
            emit(fp, "", s, "expression unary minus");
            break;

        case A_MOD:
            emit(fp, "", "mov $0, %rdx", "clear rdx because div uses rdx and rax");
            emit(fp, "", "div %rbx", "expression divide");
            emit(fp, "", "mov %rdx, %rax", "move remainder into rax for printing");
            break;

        case A_AND:
            emit(fp, "", "and %rbx, %rax", "expression and");
            break;

        case A_OR:
            emit(fp, "", "or %rbx, %rax", "expression or");
            break;
        
        case A_NOT:
            emit(fp, "", "not %rax", "expression not");
            emit(fp, "", "mov $1, %rbx", "");
            emit(fp, "", "AND %rbx, %rax", "");
            break;

        case A_LEQ:
            emit(fp, "", "cmp %rbx, %rax", "LEQ comparison");
            emit(fp, "", "setle %al", "LEQ comparison");
            emit(fp, "", "mov $1, %rbx", "");
            emit(fp, "", "and %rbx, %rax", "");
            break;
        
        case A_GEQ:
            emit(fp, "", "cmp %rbx, %rax", "GEQ comparison");
            emit(fp, "", "setge %al", "GEQ comparison");
            emit(fp, "", "mov $1, %rbx", "");
            emit(fp, "", "and %rbx, %rax", "");
            break;

        case A_LT:
            emit(fp, "", "cmp %rbx, %rax", "compare for less than");
            emit(fp, "", "setl %al", "LT comparison");
            emit(fp, "", "mov $1, %rbx", "");
            emit(fp, "", "and %rbx, %rax", "");
            break;

        case A_GT:
            emit(fp, "", "cmp %rbx, %rax", "GT comparison");
            emit(fp, "", "setg %al", "GT comparison");
            emit(fp, "", "mov $1, %rbx", "");
            emit(fp, "", "and %rbx, %rax", "");
            break;
        
        case A_EQ:
            emit(fp, "", "cmp %rbx, %rax", "EQ comparison");
            emit(fp, "", "sete %al", "EQ comparison");
            emit(fp, "", "mov $1, %rbx", "");
            emit(fp, "", "and %rbx, %rax", "");
            break;

        case A_NEQ:
            emit(fp, "", "cmp %rbx, %rax", "NEQ comparison");
            emit(fp, "", "setne %al", "NEQ comparison");
            emit(fp, "", "mov $1, %rbx", "");
            emit(fp, "", "and %rbx, %rax", "");
            break;

        default:  printf("Expression operator %d is not implemented: VERY BAD \n", p->operator);

    } // of switch

    // here we do math
    // evaluate lhs emit_expr p->S1
    // if there is a rhs, save RAX in the temp
    //      evaluate the rhs    emit_expr p->S2
    //      move rax to rbx
    //      restore the lhs to rax
    // do the operation

}

// PRE: PTR to A_IF node
// POST: GAS code for if statement
void emit_if(ASTnode* p, FILE* fp) {
    char* L1 = CreateLabel();
    char* L2 = CreateLabel();
    char s[100];

    Emit_Expr(p->S1, fp);
    emit(fp, "", "cmp $0, %rax", "check if false");
    sprintf(s, "JE %s", L1);
    emit(fp, "", s, "jump if rax equal to 0 (false)");
    Emit_AST(p->S2->S1, fp);
    sprintf(s, "JMP %s", L2);
    emit(fp, "", s, "jump to end");
    sprintf(s, "%s", L1);
    emit(fp, s, "", "");
    Emit_AST(p->S2->S2, fp);
    sprintf(s, "%s", L2);
    emit(fp, s, "", "");

}

void emit_while(ASTnode* p, FILE* fp) {
    char* L1 = CreateLabel();
    char* L2 = CreateLabel();
    char s[100];

    GOBACK = PushLabel(L1, GOBACK); 
    GETOUT = PushLabel(L2, GETOUT);
    
    emit(fp, L1, "", "label for while");
    Emit_Expr(p->S1, fp);
    emit(fp, "", "cmp $0, %rax", "check while condition");
    sprintf(s, "je %s", L2);
    emit(fp, "", s, "if while condition false, jump to exit label");
    Emit_AST(p->S2, fp);
    sprintf(s, "jmp %s", L1);
    emit(fp, "", s, "if while condition true, jump to beginning of while");
    emit(fp, L2, "", "exit label for while");
    GOBACK = GOBACK->next;
    GETOUT = GETOUT->next;

}


// PRE: PTR to AST node that points to Return or NULL decleration
// POST: GAS code for the Return, %rax is 0 for NULL and set by
//      Emit_Expr() for expression
void Emit_Return(ASTnode* p, FILE* fp) {

    if (p == NULL || p->S1 == NULL)
        emit(fp, "", "mov $0, %rax", "Default return value");
    else
        Emit_Expr(p->S1,fp);

    emit(fp,"", "leave", "leave the function");
    emit(fp, "", ".cfi_def_cfa 7, 8", "Standard end function for GAS");
    emit(fp, "", "ret", "");
    emit(fp, "", ".cfi_endproc", "Standard end function for GAS");
    emit(fp, "", ".size     main, .-main","Standard end function for GAS");
    emit(fp, "", ".ident    \"GCC: (SUSE LINUX) 7.5.0\"", "");
    emit(fp,"", ".section       .note.GNU-stack,\"\",@progbits","");
    fprintf(fp, "\n\n");

}

// PRE: PTR to AST node that points to Method
// POST: GAS code for the method, %rax is set by method
//      we run special code for external methods
void Emit_Method_Call(ASTnode* p, FILE* fp) {
    // check to see if extern method
    
    if (p->symbol->SubType == ID_Sub_Type_ExternMethod) {
        Emit_Extern_Method_Call(p,fp);
        return;
    }
    // we now know that the method is internal
}

// PRE: PTR to AST node that points to extern method
// POST: GAS code for the extern method, %rax is set by method
//      exits with error if we don't know method
void Emit_Extern_Method_Call(ASTnode* p, FILE* fp) {
    char s[100];
    // check to see if extern exists
    if (strcmp("print_string", p->name) == 0) {

        sprintf(s,"mov $%s, %rdi", p->S1->symbol->name);

        emit(fp,"",s,"RDI is the label address");
	    emit(fp, "", "mov $0, %rax", "RAX need to be zero");
	    emit(fp, "", "call printf",	"print a string");
        fprintf(fp, "\n\n");

        return;
    }
    if (strcmp("print_int", p->name) == 0) {

        Emit_Expr(p->S1->S1, fp);
        emit(fp, "","mov %rax, %rsi", "RSI needs the value to print");
        emit(fp, "","mov $percentD, %rdi", "RDI needs to be the int format");
        emit(fp, "","mov $0, %rax", "RAX needs to be 0 for printf");
        emit(fp, "","call printf", "print a number from expression");
        fprintf(fp, "\n\n");

        return;
    }
    
    if (strcmp("read_int", p->name) == 0) {
        
	    emit(fp, "", "mov $_SCANFHOLD, %rsi", "read in a number");
        emit(fp, "", "mov $percentD , %rdi", "rdi has integer format for scanf");
        emit(fp, "", "mov $0 , %rax", "No other parameters for scanf");
        emit(fp, "", "call  __isoc99_scanf", "call read");
        emit(fp,"", "mov _SCANFHOLD, %rax", "bring value on STACK into RAX register for default value");
        fprintf(fp, "\n\n");
        return;
    }

    // if we are here we don't know implementation of extern method
    fprintf(stderr, "External Method %s is unknown\n", p->name);
}


// PRE: PTR to ASSIGN
// POST: Gas code that implements the following algorithm
//  Emit the expression of S2
//  Stores that value in temporary
//  Emits the address of the LVALUE
//  extracts back from the memory the stored value
//  Stores the extracted value back into proper memory address
void Emit_Assign(ASTnode* p, FILE* fp) {
    Emit_Expr(p->S2, fp);

    // store rax into p->symbol->offset *WSIZE
    fprintf(fp, "\tmov %rax, %d(%rsp)\t# store RHS value in memory\n", p->symbol->offset*WSIZE);
    Emit_Ident(p->S1, fp); // rax has memory location of ID
    
    //PULL into RBX    p->symbol->offset *WSIZE
    fprintf(fp, "\tmov %d(%rsp), %rbx\t# Get RHS stored value", p->symbol->offset*WSIZE);
    
    //mov %RBX (%RAX)
    fprintf(fp, "\n");
    emit(fp, "", "mov %rbx, (%rax)", "Assign final store");
    fprintf(fp, "\n\n");
}

// PRE: PTR to an LVALUE or RVALUE
// POST: GAS code to make %rax exact address of the identifier
//      - upstream caller may need to extract the value from
//      - memory
void Emit_Ident(ASTnode* p, FILE* fp) {
    char s[100];
    // if an array, calculate internal offset
    // we need to shift left the LOGSIZE of that so
    // we can effectively multiply by WSIZE
    // need to check if it is global or local
    
    // global
    if (p->symbol->level == 0) {
        fprintf(fp, "\n");
        sprintf(s, "mov $%s, %%rax", p->symbol->name);
        emit(fp, "", s, "load global variable address into rax");
    }

    // local, need to load rax with stack pointer plus offset
    else {

        sprintf(s, "mov $%d, %rax", p->symbol->offset*WSIZE);
        emit(fp, "", s, "variable is local");
        emit(fp, "", "add %rsp, %rax", "");
    }


}


void Emit_string(ASTnode* p, FILE* fp) {
    if (p != NULL) {

        // string constants only appear in method arguments
        if ((p->type == A_METHODARG && p->A_Declared_Type == A_Decaf_STRING)) {

            fprintf(fp, "%s:\t%s\t\t%s\t\t\t%s\n", p->name, ".string", p->S1->name, "# global string");

        }

        Emit_string(p->next, fp);
        Emit_string(p->S1, fp);
        Emit_string(p->S2, fp);        

    }
}

// PRE: Must be passed PROGRAM->S2->S1 initally, which is the field declarations list
// POST: All fields (global variables) will be printed to fp
void Emit_Globals(ASTnode *p, FILE *fp) {
    if (p == NULL) return;
        
        if (p->S2 != NULL) {

            fprintf(fp, "%s:\t\t%s %d\t%s", p->name, ".long", p->S2->value, "# define a global variable with initital value\n");

        }
        else {

            fprintf(fp, "\t\t%s %s,%d,%d\t%s", ".comm", p->name, p->symbol->mysize*WSIZE, p->symbol->mysize*WSIZE, "# define a global variable\n");
        }
            fprintf(fp, "\t\t.align 8\n");

        Emit_Globals(p->next, fp);
}
