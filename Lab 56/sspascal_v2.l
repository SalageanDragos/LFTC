%{
#include "sspascal.tab.h"
%}

%option noyywrap
%option caseless
 
LETTER		[A-Za-z_]
DIGIT		[0-9]
NONZERODIGIT [1-9]
IDENT	LETTER{LETTER}{DIGIT} 
DELIMITATOR_1	["=<>\(\)\[\]{}:;]
OPERATOR_1		[\+\-\*/%]
COMENT		"{"[^}]*"}"
SIR_CAR		["][^\n"]*["]
CARACTER	"'"[^\n]"'"
NR_BAZA10 DIGIT+
NR_REAL		{NR_BAZA10}"."{NR_BAZA10}
%%

[\n]
[\t\n]
{COMENT}
boolean			{return BOOLEAN; }
char			{return CHAR;}
string			{return STRING;}
integer			{return INTEGER;}
real			{return REAL;}
do				{return DO;}
read			{return READ;}
write			{return WRITE;}
let				{return LET;}
if				{return IF;}
while			{return WHILE;}
else			{return ELSE;}

"<>"			{ return NE;}
"<="			{ return LE;}
">="			{ return GE;}
"=="			{ return EE;}
"<"				{ return LL;}
">"				{ return GG;}
"="				{ return ATRIB;}

{IDENT}			{return IDENTIFIER;}
{NR_REAL}		{
					yylval.p_val = yytext;
					return CONST_REAL;
				}
{NR_BAZA10}		{
					yylval.p_val = yytext;
					return CONST_INT;
				}
{CARACTER}		{
					yylval.p_val = yytext;
					return CONST_CAR;
				}
{SIR_CAR}		{
					yylval.p_val = yytext;
				return CONST_SIR;}

{DELIMITATOR_1}		{  return yytext[0];}
{OPERATOR_1}		{  return yytext[0];}
.					{  printf("Illegal token %s at line!", yytext); printf("\n"); return yytext[0]; }
%%

