%{	
	#include "code.tab.h"
%}
%x 		CMT
number		[0-9]+|[0-9]+\.[0-9]*
word		[a-zA-Z][a-zA-Z0-9]*		
%%
"/*"		{ BEGIN CMT; }
<CMT>.	 	;
<CMT>\n	;
<CMT>"*/"	{ BEGIN 0; }
program 		{ return(TPROGRAM);}
main		{ return(TMAIN);}
proc		{ return(TPROC);}
func		{ return(TFUNC);}
returns		{ return(TRETURNS);}
var		{ return(TVAR);}
int		{ return(TINT);}
long		{ return(TLONG);}
if		{ return(TIF);}
then		{ return(TTHEN);}
else		{ return(TELSE);}
while		{ return(TWHILE);}
for		{ return(TFOR);}
to		{ return(TTO);}
call		{ return(TCALL);}
return		{ return(TRETURN);}
begin		{ return(TBEGIN);}
end		{ return(TEND);}
"<="		{ return(TLE);}
">="		{ return(TGE);}
"!="		{ return(TNE);}
"="		{ return(TASS);}
"&"		{ return(TAND);}
"|"		{ return(TOR);}
"!"		{ return(TNOT);}
"<"		{ return(TLT);}
">"		{ return(TGT);}
"+"		{ return(TPLUS);}
"-"		{ return(TMINUS);}
"*"		{ return(TMUL);}
"/"		{ return(TDIV);}
"("		{ return('(');}
")"		{ return(')');}
":"		{ return(':');}
";"		{ return(';');}
"."		{ return('.');}
","		{ return(',');}
" "		;
[\r\t\n]		;
{number}		{ yylval.dval=atof(yytext); return(TNUMBER); }
{word} 		{ yylval.sval=strdup(yytext); return(TWORD); }
.		{
			printf("'%c' : illegal charactor\n", yytext[0]);
			exit(-1);
		}
