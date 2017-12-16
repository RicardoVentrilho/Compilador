%{

#include <stdio.h>
extern int yylex();
void yyerror(const char *s);

%}

%token NAME NUMBER
%start statement

%%
statement:	NAME '=' expr {$$=$1; printf ("(%d)\n", $3);}
		| expr {$$=$1; printf("=%d\n", $1); }
		;

expr:	expr '+' NUMBER {$$ = $1 + $3;}
       |expr '-' NUMBER {$$ = $1 - $3;}
       |NUMBER		{$$=$1;}
       ;

%%

extern FILE *yyin;


int main()
{
  do { yyparse();}
  while (!feof(yyin));
}

void yyerror(const char *s)
{
	fprintf(stderr,"%s\n",s);
}
