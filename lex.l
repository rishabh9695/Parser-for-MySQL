%{
#include "y.tab.h"
#include <stdio.h>
#include <stdlib.h>

#define KEYWORD(val,val1){ printf(" => %s is a KEYWORD.\n",val);return val1; /* keywords are inserted here */}
#define IDENTIFIER(val){ printf(" => %s is an IDENTIFIER.\n",val);strcpy(yylval.str, yytext); return STRING; /* Identifiers are inserted here */}
#define REALNUM(val){ printf(" => %s is a number.\n",val);yylval.id = atoi(yytext); return INTVAL; /* number are inserted here */}
#define OPERATOR(val){ printf(" => %s is an OPERATOR.\n",val);return COMPARATOR; /* comparators are inserted here */}
#define OPERATOR_(val){ printf(" => %c is an OPERATOR.\n",val);return val; }

#define error(val){printf(" => %s shows an Error \n",val);}


%}

%%

(?i:"CREATE")	                KEYWORD(yytext,CREATE)
(?i:"TABLE")                    KEYWORD(yytext,TABLE)
(?i:"SELECT")                   KEYWORD(yytext,SELECT)
(?i:"INSERT")					KEYWORD(yytext,INSERT)
(?i:"INTO")						KEYWORD(yytext,INTO)
(?i:"VALUES")					KEYWORD(yytext,VALUES)
(?i:"UPDATE")					KEYWORD(yytext,UPDATE)
(?i:"SET")						KEYWORD(yytext,SET)
(?i:"FROM")                     KEYWORD(yytext,FROM)
(?i:"DELETE")					KEYWORD(yytext,DELETE)
(?i:"WHERE")					KEYWORD(yytext,WHERE)
(?i:"DROP")						KEYWORD(yytext,DROP)
(?i:"ALTER")					KEYWORD(yytext,ALTER)
(?i:"COLUMN")					KEYWORD(yytext,COLUMN)
(?i:"ADD")						KEYWORD(yytext,ADD)
(?i:"FOREIGN") 					KEYWORD(yytext,FOREIGN)
(?i:"PRIMARY") 					KEYWORD(yytext,PRIMARY)
(?i:"KEY") 						KEYWORD(yytext,KEY)
(?i:"UNIQUE") 					KEYWORD(yytext,UNIQUE)
(?i:"DEFAULT") 					KEYWORD(yytext,DEFAULT)
(?i:"CHECK") 					KEYWORD(yytext,CHECK)
(?i:"GROUP") 					KEYWORD(yytext,GROUP)
(?i:"BY")    					KEYWORD(yytext,BY)
(?i:"ORDER") 					KEYWORD(yytext,ORDER)
(?i:"HAVING") 					KEYWORD(yytext,HAVING)
(?i:"NULL")                     KEYWORD(yytext,NULLVAL)
(?i:"NOT")                      KEYWORD(yytext,NOT)
(?i:"CHAR")                     KEYWORD(yytext,CHAR)
(?i:"VARCHAR") 					KEYWORD(yytext,VARCHAR)
(?i:"INT")                      KEYWORD(yytext,INT)
(?i:"AND")                      KEYWORD(yytext,AND)
(?i:"LIKE")                     KEYWORD(yytext,LIKE)
(?i:"COUNT")                    KEYWORD(yytext,COUNT)
(?i:"MIN")                      KEYWORD(yytext,MIN)
(?i:"MAX")                      KEYWORD(yytext,MAX)
(?i:"SUM")                      KEYWORD(yytext,SUM)
(?i:"AVG")                      KEYWORD(yytext,AVG)
(?i:"ANY")                      KEYWORD(yytext,ANY)
(?i:"ALL")                      KEYWORD(yytext,ALL)
(?i:"AS")                       KEYWORD(yytext,AS)
(?i:"REFERENCES") 				KEYWORD(yytext,REFERENCES)
(?i:"DISTINCT") 				KEYWORD(yytext,DISTINCT)
(?i:"EXISTS")  					KEYWORD(yytext,EXISTS)
(?i:"IS")                       KEYWORD(yytext,IS)
(?i:"BETWEEN")                  KEYWORD(yytext,BETWEEN)
(?i:"CONSTRAINT")               KEYWORD(yytext,CONSTRAINT)
(?i:"EXIT") 					{printf("YOU EXITED \n");}exit (EXIT_SUCCESS); /* exit command */


[a-zA-Z_][a-zA-Z0-9_]*		    IDENTIFIER(yytext)


[-][1-9][0-9]*	|
[-][1-9][0-9]*[.][0-9]* |
[-][.][0-9][0-9]*	|
[0] 	|	
[-][0][.][0-9]*  |

[1-9][0-9]*	|
[1-9][0-9]*[.][0-9]* |
[.][0-9][0-9]*	|
[0][.][0-9]*                    REALNUM(yytext)



">="							OPERATOR(">=")
"<="							OPERATOR("<=")
  
[=] 					     	OPERATOR_(yytext[0])
[<] 					    	OPERATOR_(yytext[0])
[>] 					    	OPERATOR_(yytext[0])

[+*/]                          OPERATOR_(yytext[0])
[,.&%%?|^]                     OPERATOR_(yytext[0])
[()]					       OPERATOR_(yytext[0])
[{}[]]                         OPERATOR_(yytext[0])
[;]						       OPERATOR_(yytext[0])
[-]						       OPERATOR_(yytext[0])

[\""]						   OPERATOR_(yytext[0])

[ \t\n]		         		   ;

. 						        {error(yytext);}
[0-9][0-9]*[a-zA-Z0-9_][a-zA-Z0-9_]*	{error(yytext); /* error function */}
%% 

int yywrap(void){return 1;}
