%{

#include "sintatico.tab.h"
extern int yyval;

int error_code;

%}

%%

[0-9]+		{yylval=atoi(yytext); return NUMBER;}

[a-zA-Z]+	{return NAME;}

[ \t]		; /* delimitadores - ignorar */

\n		{return 0;}

.		{ return yytext[0];} 		

%%
