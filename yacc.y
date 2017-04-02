%{
#include <stdio.h>
void yyerror (char *s);
%}

/* line is the starting terminal */
%start line 

/* tokens for sql */
%token CREATE TABLE INT CHAR NOT NULLVAL FROM SELECT INSERT INTO VALUES SET UPDATE DELETE DROP ALTER ADD COLUMN ALL DISTINCT WHERE IN REFERENCES PRIMARY FOREIGN DEFAULT UNIQUE KEY ANY VARCHAR EXISTS CHECK STRING INTVAL GROUP BY ORDER HAVING AND LIKE COUNT MIN MAX SUM AVG AS BETWEEN CONSTRAINT IS

%union { double id; char str[100];}															
%type <str> STRING element
%type <id> INTVAL

/*  left associative operators */
%left AND
%left OR 								
%left NOT
%left COMPARATOR

%%

line 				: P1 semicolon 	| P2 semicolon   | P3 semicolon  | P4 semicolon   
                    | P5 semicolon  | P6 semicolon   | P7 semicolon   | P8 semicolon  
                    | P9 semicolon   | P10 semicolon
					| line P1 semicolon  | line P2 semicolon
                    | line P3 semicolon  | line P4 semicolon
                    | line P5 semicolon  | line P6 semicolon
                    | line P7 semicolon  | line P8 semicolon
                    | line P9 semicolon  | line P10 semicolon
                    ;

semicolon 			: ';'
					;

P1                  : DROP TABLE element 					/* drop table production rule*/
                    ;

P2        			: ALTER TABLE element DROP COLUMN element /* drop column production rule*/
                    ;


P3                  : DELETE FROM element WHERE condition	/* delete production rule */
                    ;

P4 				    : INSERT INTO element '(' element B_V V ')'	/* insert production rule with optional attributes*/
                    ;

P5					: INSERT INTO element VALUES '(' attr ')' /*  insert production rule  */
					;

P6					: CREATE TABLE element '(' table_attr ')' /* create table production rule*/	
					;

P7					:SELECT col_list1 FROM col_list WHERE condition /*  selection with conditions production rule */
					;

P8					:ALTER TABLE element ADD entry  /*add entry production rule*/
					;

P9					:UPDATE element SET setcolumn WHERE condition /* update production rule*/
					;

P10					:SELECT col_list1 FROM col_list  /*selection without conditions production rule*/
					;

//P6 production rules
table_attr			:entry columnlist keys
					;

entry				:element datatype
					;

datatype			:INT|CHAR varlength|VARCHAR varlength
					;

varlength			:'(' INTVAL ')'
					;


columnlist			:/*empty string*/|entry columnlist
					;

keys				:/*empty string*/|',' keyele keys


keyele				:constra PRIMARY KEY '(' col_list ')'
					|constra FOREIGN KEY '(' element ')' REFERENCES element '(' element ')'
					;

constra 			:CONSTRAINT element
					;


//P9 production rules
setcolumn			:setattr setprime
					;

setattr 			:element '=' V
					;

setprime			:/*empty string*/|',' setattr setprime
					;

//P5 production rules
attr 				:V V_prime
					;

V_prime				:/*empty string*/|',' V V_prime
					;

//P4 production rules

B_V					:')' VALUES '('|',' element B_V V 
					;

// production rules involving condition
condition           :sub_condition c_prime
					;

c_prime 			:/*empty string */|and_or sub_condition c_prime
					; 


sub_condition       :double_o
					|word_o
					|not_word_o
					|id_and_nest
					;


double_o			:element OP element
					|element OP INTVAL
					|INTVAL OP element
					;


word_o              :EXISTS sub_q|IS NULLVAL sub_q|UNIQUE sub_q
					;

not_word_o			:NOT EXISTS sub_q
					;

id_and_nest			:element OP sub_q|element word_ops sub_q
					;

word_ops			:IN|BETWEEN
					;

sub_q				:'(' SELECT col_list1 FROM col_list WHERE condition ')'
					;


// common production rules
col_list1			:col_list|'*'
					;

col_list			:element id_list
					;

id_list 			:/*empty string */|',' element id_list
					;

V 					: element|INTVAL
					;

and_or				:AND|OR
					;

OP  				:'='|'<'|'>'|'<' OP1|'>' OP1
					;

OP1 				:'='
					;

element				: STRING					
					;

%%

int main(void)
{
	return yyparse();
}

void yyerror(char *s)
{
	fprintf(stderr, "%s\n", s);
}