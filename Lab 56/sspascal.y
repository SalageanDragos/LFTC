%{
#include <stdio.h>
#include <stdlib.h>
#define YYDEBUG 1

#define TIP_INT 1
#define TIP_REAL 2
#define TIP_CAR 3

double stiva[20];
int sp;

void push(double x)
{ stiva[sp++]=x; }

double pop()
{ return stiva[--sp]; }

%}

%union {
  	int l_val;
	char *p_val;
}

%token BEGINN
%token CONST
%token DO
%token ELSE
%token END
%token IF
%token PRINT
%token PROGRAM
%token READ
%token THEN
%token VAR
%token WHILE
%token LL
%token NUMBER
%token lista_elem
%token GG
%token ID
%token WRITE
%token LET
%token <p_val> CONST_INT
%token <p_val> CONST_REAL
%token <p_val> CONST_CAR
%token CONST_SIR
%token CHAR
%token INTEGER
%token REAL
%token BOOLEAN
%token STRING
%token EE
%token IDENTIFIER
%token ATRIB
%token NE
%token LE
%token GE

%left '+' '-'
%left DIV MOD '*' '/'
%left OR
%left AND
%left NOT

%%
program : LET "{" decllist "}"   cmpdstmt   
		;
decllist : declaration ";" 
		| declaration ";" decllist 
		;
declaration : type IDENTIFIER ";" 
		| type MultNames ";" 
MultNames : IDENTIFIER 
		| IDENTIFIER "," MultNames 
		;
type1 : BOOLEAN 
		| CHAR
		| INTEGER
		| REAL
		| STRING
		;
arraydecl : type1 "[" NUMBER "]" 
		;
type  : type1
		|arraydecl 
		;
cmpdstmt : DO "{"  stmtlist   "}" 
		;
stmtlist :stmt    
		| stmt     stmtlist 
		;
stmt : simplstmt ";"
		| structstmt
		;
simplstmt : assignstmt 
		| iostmt ";" 
		;
assignstmt : IDENTIFIER "=" expression 
		| IDENTIFIER "[" NUMBER "]" expression 
		;
expression : expression "+" expression 
		| expression "-" expression 
		| term 
		;
term :  term "*" factor 
		|term "/" factor 
		| term "%" 
		| factor
		;
factor : "(" expression ")" 
		| IDENTIFIER 
		| IDENTIFIER "[" NUMBER"]" 
		;
iostmt : READ 
		| WRITE "(" IDENTIFIER ")" 
		;
structstmt : ifstmt 
		| whilestmt 
		;
ifstmt : IF"(" condition ")" cmpdstmt ELSE cmpdstmt 
		;
whilestmt : WHILE"(" condition ")"  cmpdstmt 
		;
condition : expression RELATION expression 
		;
RELATION : NE
		| LE
		| GE 
		| EE 
		| GG 
		| LL 
		;



%%

yyerror(char *s)
{
  printf("%s\n", s);
}

extern FILE *yyin;

main(int argc, char **argv)
{
  if(argc>1) yyin = fopen(argv[1], "r");
  if((argc>2)&&(!strcmp(argv[2],"-d"))) yydebug = 1;
  if(!yyparse()) fprintf(stderr,"\tO.K.\n");
}

