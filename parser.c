#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define YES 1
#define NO 0

int selector(char *a){
	char* keywords[]={"IS","CONSTRAINT","REFERENCES","OR","REAL","EXISTS","CREATE","TABLE","SELECT","INSERT","INTO","VALUES","UPDATE","SET","FROM","DELETE","WHERE","DROP","ALTER","COLUMN","ADD","FOREIGN","PRIMARY","KEY","UNIQUE","DEFAULT","CHECK","GROUP","BY","ORDER","HAVING","NOT","NULL","CHAR","VARCHAR","INT","AND","LIKE","COUNT","MIN","MAX","SUM","AVG","ANY","ALL","AS"};
	char *o[]={"=","<>","<=",">=","<",">","*","-","+","!=","/",";"};
	char *s[]={",","%","&",".","(",")"};
	int i,c=0;
	for(i=0;i<46;i++)
	{	
		if(strcasecmp(a,keywords[i])==0)
		{	
			return 1;
		}
	}
	for(i=0;i<12;i++)
	{	
		if(strcasecmp(a,o[i])==0)
		{	
			return 2;
		}
	}
	for(i=0;i<6;i++)
	{	
		if(strcasecmp(a,s[i])==0)
		{	
			return 3;
		}
	
	}
	//string detector
	int a_len = strlen(a);//
	if(((a[0] == 39)&&(a[a_len-1] == 39))||((a[0] == 34)&&(a[a_len-1] == 34)))
	{
		return 6;
	}


//num
	for(i=0;i<strlen(a);i++)
	{
		if(a[i]!=46 && (a[i]<48 || a[i]>57))
		break;
		else if(a[i]==46)
		c++;
	}
	if(c>1);
	else if(i==strlen(a))
		return 4;
//alpha
	if(a[0]<65 || (a[0]>90 && a[0]<97) || a[0]>122)
		return 0;
	for(i=1;i<strlen(a);i++){
		if((a[i]>=65 && a[i]<=90) || (a[i]>=97 && a[i]<=122) || (a[i]>=48 && a[i]<=57) || a[i]==95)
			;
		else
			return 0;
	}
	return 5;
}

//global 
char M[100][30];
char prod[50][100];
int prod_pos = 0;
int M_length = 0;
int parse_pos = 0;
int flag[11];

int P1();
int P2();
int P3();
int P4();
int P5();
int P6();
int P7();
int P8();
int P9();
int P10();
int DROP();
int TABLE();
int ID();
int SEMI();
int ALTER();
int COLUMN();
int DELETE();
int FROM();
int WHERE();
int CONDITION();
int VAL();
int OP();
int Double_O();
int STR();
int V();
int INSERT();
int INTO();
int OPN_BRKT();
int CLS_BRKT();
int BR_V();
int COMMA();
int V_PRIME();
int ATTR();
int VALUES();
int TABLEATTR();
int ENTRY();
int DATATYPE();
int VARLENGTH();
int SELECT();
int COL_LIST();
int ID_LIST();
int Word_O();
int Sub_Q();
int IS();
int NUll();
int UNIQUE();
int EXISTS();
int Not_Word_O();
int ID_AND_NEST();
int NOT();
int C_PRIME();
int AND_OR();
int CREATE();
int TABLEATTR();
int COLUMNLIST();
int ENTRY();
int KEYS();
int VARATTR();
int ISNULL();
int UNIQUE();
int ADD();
int UPDATE();
int SET();
int SETCOLUMN();
int SETATTR();
int SETPRIME();
int EQUALS();
int SUB_CONDITION();
int word_ops();
int KEYELE();
int CONSTRA();
int PRIMARY();
int KEY();
int FOREIGN();
int REFERENCES();
int CONSTRAINT();
int UNIQ2();
int COL_LIST1();
int STAR();



int Start_State()
{
	//printf("entered start\n");
	int SS_pos = parse_pos;
	if(P1() == 1)
	{
		strcpy(prod[prod_pos]," S -> P1");
		prod_pos++;
		return 1;
	}
	parse_pos = SS_pos;
	if(P2() == 1)
	{
		strcpy(prod[prod_pos]," S -> P2");
		prod_pos++;
		return 1;
	}
	parse_pos = SS_pos;
	if(P3() == 1)
	{
		strcpy(prod[prod_pos]," S -> P3");
		prod_pos++;
		return 1;
	}
	parse_pos = SS_pos;
//printf("entering P4\n");
	if(P4() == 1)
	{	
		strcpy(prod[prod_pos]," S -> P4");
		prod_pos++;
		return 1;
	}
	parse_pos = SS_pos;
//printf("entering P5 %d\n",parse_pos );
	if(P5() == 1)
	{	
		strcpy(prod[prod_pos]," S -> P5");
		prod_pos++;	
		return 1;
	}
	parse_pos = SS_pos;
	if(P6()== 1)
	{
		strcpy(prod[prod_pos]," S -> P6");
		prod_pos++;
		return 1;
	}
	parse_pos = SS_pos;
	if(P7()== 1)
	{
		strcpy(prod[prod_pos]," S -> P7");
		prod_pos++;
		return 1;
	}
	parse_pos = SS_pos;
	if(P8()==1)
	{
		strcpy(prod[prod_pos]," S -> P8");
		prod_pos++;
		return 1;
	}
	parse_pos = SS_pos;
	if(P9()==1)
	{
		strcpy(prod[prod_pos]," S -> P9");
		prod_pos++;
		return 1;
	}
	parse_pos = SS_pos;
	if(P10()==1)
	{
		strcpy(prod[prod_pos]," S -> P10");
		prod_pos++;
		return 1;
	}
	parse_pos = SS_pos;
	return 0;
}

int P1()
{
	if( (DROP() && TABLE() && ID() && SEMI()) == 1)
	{
		strcpy(prod[prod_pos]," P1 -> DROP TABLE id ;");
		prod_pos++;
		return 1;
	}
	//printf("entered P1\n");	
	//return (DROP() && TABLE() && ID() && SEMI());
}

int P2()
{
	if( ( ALTER() && TABLE() && ID() && DROP() && COLUMN() && ID() ) == 1)
	{
		strcpy(prod[prod_pos]," P2 -> ALTER TABLE id DROP COLUMN id ;");
		prod_pos++;
		return 1;
	}
	//return ( ALTER() && TABLE() && ID() && DROP() && COLUMN() && ID() );
}
int P3()
{
	if( (DELETE() && FROM() && ID() && WHERE() && CONDITION() && SEMI()) == 1)
	{
		strcpy(prod[prod_pos]," P3 -> DELETE FROM id WHERE CONDITION ; ");
		prod_pos++;
		return 1;
	}
	//printf("entered P2\n");	
	//return (DELETE() && FROM() && ID() && WHERE() && CONDITION() && SEMI());
}
int P4()
{
	int P4_pos = parse_pos;
	if(( INSERT() && INTO() && ID() && OPN_BRKT() && ID() && BR_V() && V() && CLS_BRKT() && SEMI() ) == 1 )
	{
		strcpy(prod[prod_pos]," P4 -> INSERT INTO id ( id BR_V V ) ; ");
		prod_pos++;
		return 1;
	}
	
}
int P5()
{
	if( ( INSERT() & INTO() & ID() & VALUES() & OPN_BRKT() & ATTR() & CLS_BRKT() & SEMI() ) == 1)
	{
		strcpy(prod[prod_pos]," P5 -> INSERT INTO id VALUES ( ATTR ) ; ");
		prod_pos++;
		return 1;
	}
	//printf("P5 entered %d\n",parse_pos );
	//return ( INSERT() & INTO() & ID() & VALUES() & OPN_BRKT() & ATTR() & CLS_BRKT() & SEMI() );
}
int P6()
{
	if( (CREATE() && TABLE() && ID() && OPN_BRKT() && TABLEATTR() && CLS_BRKT() && SEMI()) == 1)
	{
		strcpy(prod[prod_pos]," P6 -> CREATE TABLE id ( TABLEATTR ) ; ");
		prod_pos++;
		return 1;
	}
	//printf("entered P6\n");	
	//return (CREATE() && TABLE() && ID() && OPN_BRKT() && TABLEATTR() && CLS_BRKT() && SEMI());
}
int P7()
{
	if( ( SELECT() && COL_LIST1() && FROM() && COL_LIST() && WHERE() && CONDITION() && SEMI() ) == 1)
	{
		strcpy(prod[prod_pos]," P7 -> SELECT COL_LIST1 FROM COL_LIST WHERE CONDITION ; ");
		prod_pos++;
		return 1;
	}
	//return( SELECT() && COL_LIST() && FROM() && COL_LIST() && WHERE() && CONDITION() && SEMI() );
}
int P8()
{
	if( ( ALTER() && TABLE() && ID() && ADD() && ENTRY() && SEMI() ) == 1 )
	{
		strcpy(prod[prod_pos]," P8 -> ALTER TABLE id ADD ENTRY ; ");
		prod_pos++;
		return 1;
	}
	//printf("entered P8\n");
	//return ( ALTER() && TABLE() && ID() && ADD() && ENTRY() && SEMI() );
}
int P9()
{
	if( ( UPDATE() && ID() && SET() && SETCOLUMN() && WHERE() && CONDITION() && SEMI() ) == 1 )
	{
		strcpy(prod[prod_pos]," P9 -> UPDATE id SET SETCOLUMN WHERE CONDITION ; ");
		prod_pos++;
		return 1;
	}
	//printf("entered P9\n");
	//return ( UPDATE() && ID() && SET() && SETCOLUMN() && WHERE() && CONDITION() && SEMI() );
}
int P10()
{
	if( ( SELECT() && COL_LIST1() && FROM() && COL_LIST() && SEMI() ) == 1)
	{
		strcpy(prod[prod_pos]," P10 -> SELECT COL_LIST1 FROM COL_LIST ; ");
		prod_pos++;
		return 1;
	}
	//return( SELECT() && COL_LIST() && FROM() && COL_LIST() && WHERE() && CONDITION() && SEMI() );
}
int COL_LIST1()
{
	int COL_LIST1_pos = parse_pos;
	if( COL_LIST()==1)
	{
		strcpy(prod[prod_pos]," COL_LIST1 -> COL_LIST ");
		prod_pos++;
		return 1;
	}
	parse_pos = COL_LIST1_pos;
	if(STAR()==1)
	{
		strcpy(prod[prod_pos]," COL_LIST1 -> * ");
		prod_pos++;
		return 1;
	}
	
	parse_pos = COL_LIST1_pos;
	
	return 0;
}
int STAR()
{
	if(strcasecmp(M[parse_pos],"*") == 0)
	{
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}

int UPDATE()
{
	if(strcasecmp(M[parse_pos],"UPDATE") == 0)
	{
		flag[9]=YES;
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int SET()
{
	if(strcasecmp(M[parse_pos],"SET") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}

int ATTR()
{
	if( ( V() && V_PRIME()) == 1)
	{
		strcpy(prod[prod_pos]," ATTR -> V V_PRIME ");
		prod_pos++;

		return 1;
	}
	//return( SETATTR() && SETPRIME());
}
int SETCOLUMN()
{
	if( ( SETATTR() && SETPRIME()) == 1)
	{
		strcpy(prod[prod_pos]," SETCOLUMN -> SETATTR SETPRIME ");
		prod_pos++;

		return 1;
	}
	//return( SETATTR() && SETPRIME());
}

int SETATTR()
{
	if( ( ID() && EQUALS() && V()) == 1)
	{
		strcpy(prod[prod_pos]," SETATTR -> ID = V ");
		prod_pos++;

		return 1;
	}
	//return( ID() && EQUALS() && V());
}
int EQUALS()
{
	if(strcasecmp(M[parse_pos],"=") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int SETPRIME()
{
	int SETPRIME_pos = parse_pos;
	if( (COMMA() && SETATTR() && SETPRIME()) == 1 )
	{
		strcpy(prod[prod_pos]," SETPRIME -> , SETATTR SETPRIME ");
		prod_pos++;

		return 1;
	}
	parse_pos = SETPRIME_pos;

		strcpy(prod[prod_pos]," SETPRIME -> null ");
		prod_pos++;

	return 1;
}
int ISNULL()
{
	if(strcasecmp(M[parse_pos],"NULL") == 0)
	{
		// strcpy(prod[prod_pos]," ISNULL -> null");
		// prod_pos++;

	parse_pos++;	
	}
	else if(strcasecmp(M[parse_pos],"NOT") == 0 && strcasecmp(M[parse_pos+1],"NULL") == 0)
	{
	parse_pos+=2;
	}
	return 1;
}
int ADD()
{
	if(strcasecmp(M[parse_pos],"ADD") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int Sub_Q()
{
	if(( OPN_BRKT() && SELECT() && COL_LIST1() && FROM() && COL_LIST() && WHERE() && CONDITION() && CLS_BRKT() ) == 1 )
	{
		strcpy(prod[prod_pos]," Sub_Q -> ( SELECT COL_LIST1 FROM COL_LIST WHERE CONDITION )");
		prod_pos++;
		return 1;
	}
}
int COL_LIST()
{
	if( (ID() && ID_LIST()) ==1 )
	{
		strcpy(prod[prod_pos]," COL_LIST -> id ID_LIST ");
		prod_pos++;

		return 1;
	}
	//return (ID() && ID_LIST());
}
int ID_LIST()
{
	int ID_LIST_pos=parse_pos;
	if( (COMMA() && ID() && ID_LIST()) == 1 )
	{
		strcpy(prod[prod_pos]," ID_LIST -> , id ID_LIST ");
		prod_pos++;

		return 1;
	}

	strcpy(prod[prod_pos]," ID_LIST -> null ");
	prod_pos++;

	parse_pos = ID_LIST_pos;
	return 1;
}
int SELECT()
{
	//printf("entered Create %s \n",M[parse_pos]);	

	if(strcasecmp(M[parse_pos],"SELECT") == 0)
	{
		flag[7]=YES;
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int CREATE()
{
	//printf("entered Create %s \n",M[parse_pos]);	

	if(strcasecmp(M[parse_pos],"CREATE") == 0)
	{
		flag[6]=YES;
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int COLUMNLIST()
{
	//printf("entered columnlist %s \n",M[parse_pos]);
	int columnlist_pos=parse_pos;
	if((COMMA() && ENTRY() && COLUMNLIST())==1){
		strcpy(prod[prod_pos]," COLUMNLIST -> , ENTRY COLUMNLIST ");
		prod_pos++;
		//printf("exited columnlist true%s \n",M[parse_pos]);
		return 1;
	}
	//printf("entered columnlist pseudotrue%s \n",M[parse_pos]);
	parse_pos=columnlist_pos;

		strcpy(prod[prod_pos]," COLUMNLIST -> null ");
		prod_pos++;

	return 1;
}
int KEYS()
{
	//printf("entered keys %s \n",M[parse_pos]);
	int keys_pos = parse_pos;
	if( (COMMA() && KEYELE() && KEYS()) == 1 )
	{
		strcpy(prod[prod_pos]," KEYS -> , KEYELE KEYS ");
		prod_pos++;

		return 1;
	}
	parse_pos = keys_pos;

	strcpy(prod[prod_pos]," KEYS -> null ");
		prod_pos++;
	return 1;
}
int KEYELE()
{
	//printf("entered keyele %s \n",M[parse_pos]);
	int KEYELE_pos = parse_pos;
	if( CONSTRA() && PRIMARY() && KEY() && OPN_BRKT() && COL_LIST() && CLS_BRKT()== 1)
	{
		strcpy(prod[prod_pos]," KEYELE -> CONSTRA PRIMARY KEY ( COL_LIST ) ");
		prod_pos++;
		return 1;
	}
	parse_pos = KEYELE_pos;
	if(CONSTRA() && FOREIGN() && KEY() && OPN_BRKT() && ID() && CLS_BRKT() && REFERENCES() && ID() && OPN_BRKT() && ID() && CLS_BRKT()==1)
	{
		strcpy(prod[prod_pos]," KEYELE -> CONSTRA FOREIGN KEY ( id ) REFERENCES id ( id ) ");
		prod_pos++;
		return 1;
	}
	
	parse_pos = KEYELE_pos;
	
	return 0;
}

int CONSTRA()
{
	//printf("entered constra %s \n",M[parse_pos]);
	int CONSTRA_pos = parse_pos;
	if( (CONSTRAINT() && ID() == 1 ))
	{
		return 1;
	}
	parse_pos = CONSTRA_pos;

	return 1;
}

int CONSTRAINT()
{
	if(strcasecmp(M[parse_pos],"CONSTRAINT") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}

int PRIMARY()
{
	//printf("entered primary %s \n",M[parse_pos]);
	if(strcasecmp(M[parse_pos],"PRIMARY") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}

int FOREIGN()
{
	//printf("entered foreign %s \n",M[parse_pos]);
	if(strcasecmp(M[parse_pos],"FOREIGN") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int KEY()
{
	if(strcasecmp(M[parse_pos],"KEY") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}

int REFERENCES()
{
	if(strcasecmp(M[parse_pos],"REFERENCES") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int VARATTR()
{
	//printf("varattr %s \n",M[parse_pos]);
	if ( (ISNULL() && UNIQ2()) == 1 )
	{
		// strcpy(prod[prod_pos]," VARATTR -> ISNULL UNIQ2 ");
		// prod_pos++;
		return 1;
	}
	//return (ISNULL() && UNIQ2());
}
int ENTRY()
{
	if( (ID() && DATATYPE() && VARATTR()) == 1 )
	{
		strcpy(prod[prod_pos]," ENTRY -> id DATATYPE ");
		prod_pos++;

		return 1;
	}
	//printf("entered entry %s \n",M[parse_pos]);
	//return (ID() && DATATYPE() && VARATTR());
}
int TABLEATTR()
{
	//printf("entered tableattr %s \n",M[parse_pos]);
	if( (ENTRY() && COLUMNLIST() && KEYS()) == 1 )
	{
		strcpy(prod[prod_pos]," TABLEATTR -> ENTRY COLUMNLIST KEYS ");
		prod_pos++;

		return 1;
	}
	//return (ENTRY() && COLUMNLIST() && KEYS());
}
int DATATYPE()
{
	//printf("entered datatype %s \n",M[parse_pos]);
	if(strcasecmp(M[parse_pos],"INT") == 0)
	{
		strcpy(prod[prod_pos]," DATATYPE -> int ");
		prod_pos++;
	parse_pos++;
	return 1;	
	}
	else if(strcasecmp(M[parse_pos],"REAL") == 0)
	{
		strcpy(prod[prod_pos]," DATATYPE -> real ");
		prod_pos++;
	parse_pos++;
	return 1;	
	}
	else if(strcasecmp(M[parse_pos],"CHAR") == 0)
	{
		strcpy(prod[prod_pos]," DATATYPE -> char VARLENGTH ");
		prod_pos++;
	parse_pos++;
	return VARLENGTH();
	}
	else if(strcasecmp(M[parse_pos],"VARCHAR") == 0)
	{
		strcpy(prod[prod_pos]," DATATYPE -> varchar VARLENGTH ");
		prod_pos++;
	parse_pos++;
	return VARLENGTH();
	}
	else
	{
		return 0;
	}
}
int VARLENGTH()
{
	if( (OPN_BRKT() & VAL() & CLS_BRKT()) == 1 )
	{
		strcpy(prod[prod_pos]," VARLENGTH -> ( val ) ");
		prod_pos++;

		return 1;
	}
	//return (OPN_BRKT() & VAL() & CLS_BRKT()); 
}

int V_PRIME()
{
	int V_PRIME_pos = parse_pos;
	if( (COMMA() && V() && V_PRIME()) == 1 )
	{
		strcpy(prod[prod_pos]," V_PRIME -> , V V_PRIME ");
		prod_pos++;
		return 1;
	}
	parse_pos = V_PRIME_pos;

	strcpy(prod[prod_pos]," V_PRIME -> null ");
	prod_pos++;
	return 1;
}
int BR_V()
{
	int BR_V_pos = parse_pos;
	if(( CLS_BRKT() && VALUES() && OPN_BRKT() ) == 1)
	{
		strcpy(prod[prod_pos]," BR_V -> ) VALUES ( ");
			printf("parse_pos is %d\n", parse_pos);
		prod_pos++;
		return 1;
	}
	parse_pos = BR_V_pos;
	if(( COMMA() && ID() && BR_V() && VAL() && COMMA() ) == 1)
	{
		strcpy(prod[prod_pos]," BR_V -> , id BR_V val , ");
		prod_pos++;
		return 1;
	}
	parse_pos = BR_V_pos;
	if(( COMMA() && ID() && BR_V() && STR() && COMMA() ) == 1)
	{
		strcpy(prod[prod_pos]," BR_V -> , id BR_V string , ");
		prod_pos++;
		return 1;
	}
	parse_pos = BR_V_pos;
	
	return 0;
}
int VALUES()
{
	if(strcasecmp(M[parse_pos],"VALUES") == 0)
	{
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int COMMA()
{
	if(strcasecmp(M[parse_pos],",") == 0)
	{
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int OPN_BRKT()
{
	//printf("entered OPN_BRKT\n");
	if(strcasecmp(M[parse_pos],"(") == 0)
	{
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int CLS_BRKT()
{
	if(strcasecmp(M[parse_pos],")") == 0)
	{
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int DELETE()
{
	//printf("entered TABLE %s \n",M[parse_pos]);	

	if(strcasecmp(M[parse_pos],"DELETE") == 0)
	{
		flag[3]=YES;
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int FROM()
{
	//printf("entered TABLE %s \n",M[parse_pos]);	

	if(strcasecmp(M[parse_pos],"FROM") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int WHERE()
{
	//printf("entered TABLE %s \n",M[parse_pos]);	

	if(strcasecmp(M[parse_pos],"WHERE") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int DROP()
{
	//printf("entered DROP %s \n",M[parse_pos]);	

	if(strcasecmp(M[parse_pos],"DROP") == 0)
	{
		flag[1] = YES;

		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}

int TABLE()
{
	//printf("entered TABLE %s \n",M[parse_pos]);	

	if(strcasecmp(M[parse_pos],"TABLE") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int ID()
{
	//printf("entered ID %s \n",M[parse_pos]);	

	if(strcasecmp(M[parse_pos],"ID") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int SEMI()
{
	//printf("entered SEMI %s \n",M[parse_pos]);	

	if(strcasecmp(M[parse_pos],";") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int ALTER()
{
	if(strcasecmp(M[parse_pos],"ALTER") == 0)
	{
		flag[2]=YES;
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int INSERT()
{
//printf("entered Insert\n");
	if(strcasecmp(M[parse_pos],"INSERT") == 0)
	{
		flag[4]=YES;
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int INTO()
{
//printf("entered INTO\n");
	if(strcasecmp(M[parse_pos],"INTO") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int NOT()
{
	if(strcasecmp(M[parse_pos],"NOT") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int COLUMN()
{
	if(strcasecmp(M[parse_pos],"COLUMN") == 0)
	{
		//printf("%d\n", parse_pos);
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int CONDITION()
{
	if( ( SUB_CONDITION() && C_PRIME() ) == 1)
	{
		strcpy(prod[prod_pos]," CONDITION -> SUB_CONDITION C_PRIME ");
		prod_pos++;
		return 1;
	}
	//return ( SUB_CONDITION() && C_PRIME() );
}
int C_PRIME()
{
	int C_PRIME_pos = parse_pos;
	if( (AND_OR() && SUB_CONDITION() && C_PRIME()) == 1 )
	{
		strcpy(prod[prod_pos]," C_PRIME -> AND_OR SUB_CONDITION C_PRIME ");
		prod_pos++;
		return 1;
	}
	parse_pos = C_PRIME_pos;

	strcpy(prod[prod_pos]," C_PRIME -> null ");
	prod_pos++;
	return 1;
}
int AND_OR()
{
	if(strcasecmp(M[parse_pos],"AND") == 0)
	{
		strcpy(prod[prod_pos]," AND_OR -> AND ");
		prod_pos++;	
		parse_pos++;
		return 1;	
	}
	else if(strcasecmp(M[parse_pos],"OR") == 0)
	{
		strcpy(prod[prod_pos]," AND_OR -> OR ");
		prod_pos++;	
		parse_pos++;
		return 1;	
	}
	else
	{
		return 0;
	}
}
int SUB_CONDITION()
{

	int cond_pos = parse_pos;
	if( Double_O() == 1)
	{		
		strcpy(prod[prod_pos]," SUB_CONDITION -> Double_O ");
		prod_pos++;	
		return 1;
	}
	parse_pos = cond_pos;
	if( Word_O() == 1)
	{
		strcpy(prod[prod_pos]," SUB_CONDITION -> Word_O ");
		prod_pos++;	
		return 1;
	}
	parse_pos = cond_pos;
	if( Not_Word_O() == 1)
	{
		strcpy(prod[prod_pos]," SUB_CONDITION -> Not_Word_O ");
		prod_pos++;	
		return 1;
	}
	parse_pos = cond_pos;
	if( ID_AND_NEST() == 1)
	{
		strcpy(prod[prod_pos]," SUB_CONDITION -> ID_AND_NEST ");
		prod_pos++;	
		return 1;
	}
	parse_pos = cond_pos;

	return 0;
}
int ID_AND_NEST()
{
	int ID_AND_NEST_pos = parse_pos;
	if( ID() && OP() && Sub_Q() )
	{
		strcpy(prod[prod_pos]," ID_AND_NEST -> ID OP Sub_Q ");
		prod_pos++;
		return 1;
	}
	parse_pos = ID_AND_NEST_pos;
	if( ID() && word_ops() && Sub_Q() )
	{
		strcpy(prod[prod_pos]," ID_AND_NEST -> ID word_ops Sub_Q ");
		prod_pos++;
		return 1;
	}
	parse_pos = ID_AND_NEST_pos;

	return 0;
}
int Not_Word_O()
{
	int Word_O_pos = parse_pos;
	if( ( NOT() && EXISTS() && Sub_Q() ) == 1 )
	{
		strcpy(prod[prod_pos]," Not_Word_O -> NOT EXISTS Sub_Q ");
		prod_pos++;
		return 1;
	}
	
	parse_pos = Word_O_pos;

	return 0;
}
int Word_O()
{
	int Word_O_pos = parse_pos;
	if( (EXISTS() && Sub_Q() ) == 1 )
	{
		strcpy(prod[prod_pos]," Word_O -> EXISTS Sub_Q ");
		prod_pos++;
		return 1;
	}
	parse_pos = Word_O_pos;
	if( (IS() && NUll() && Sub_Q() ) == 1 )
	{
		strcpy(prod[prod_pos]," Word_O -> IS NULL Sub_Q ");
		prod_pos++;
		return 1;
	}
	parse_pos = Word_O_pos;
	if( (UNIQUE() && Sub_Q() ) == 1 )
	{
		strcpy(prod[prod_pos]," Word_O -> UNIQUE Sub_Q ");
		prod_pos++;
		return 1;
	}
	parse_pos = Word_O_pos;
	return 0;
}
int UNIQ2()
{
	if(UNIQUE()==1);
	return 1;
}
int UNIQUE()
{
	if(strcasecmp(M[parse_pos],"UNIQUE") == 0)
	{
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int IS()
{
	if(strcasecmp(M[parse_pos],"IS") == 0)
	{
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int NUll()
{
	if(strcasecmp(M[parse_pos],"NULL") == 0)
	{
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int EXISTS()
{
	if(strcasecmp(M[parse_pos],"EXISTS") == 0)
	{
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}
int Double_O()
{
	int Double_O_pos = parse_pos;
	if((ID() && OP() && ID()) == 1)
	{
		strcpy(prod[prod_pos]," Double_O -> id OP id ");
		prod_pos++;
		//printf("1\n");
		return 1;
	}
	parse_pos = Double_O_pos;
	if((ID() && OP() && V()) == 1)
	{
		strcpy(prod[prod_pos]," Double_O -> id OP V ");
		prod_pos++;
		//printf("2\n");
		return 1;
	}
	parse_pos = Double_O_pos;
	if((V() && OP() && ID()) == 1)
	{
		strcpy(prod[prod_pos]," Double_O -> V OP id ");
		prod_pos++;
		//printf("3\n");
		return 1;
	}
	parse_pos = Double_O_pos;
	return 0;
}
int V()
{
	int V_pos = parse_pos;
	if(STR() == 1)
	{
		strcpy(prod[prod_pos]," V -> string ");
		prod_pos++;

		return 1;
	}
	parse_pos = V_pos;
	if(VAL() == 1)
	{
		strcpy(prod[prod_pos]," V -> val ");
		prod_pos++;

		return 1;
	}
	parse_pos = V_pos;
	return 0;
}
int STR()
{
	if(strcasecmp(M[parse_pos],"string") == 0)
	{
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}

int OP()
{
	if(strcasecmp(M[parse_pos],"=") == 0)
	{
		// strcpy(prod[prod_pos]," OP -> = ");
		// prod_pos++;
	parse_pos++;
	return 1;	
	}
	else if(strcasecmp(M[parse_pos],"<") == 0)
	{
		// strcpy(prod[prod_pos]," OP -> < ");
		// prod_pos++;
	parse_pos++;
	return 1;
	}
	else if(strcasecmp(M[parse_pos],">") == 0)
	{
		// strcpy(prod[prod_pos]," OP -> > ");
		// prod_pos++;
	parse_pos++;
	return 1;	
	}
	else if(strcasecmp(M[parse_pos],"<=") == 0)
	{
		// strcpy(prod[prod_pos]," OP -> <= ");
		// prod_pos++;
	parse_pos++;
	return 1;	
	}
	else if(strcasecmp(M[parse_pos],">=") == 0)
	{
		// strcpy(prod[prod_pos]," OP -> >= ");
		// prod_pos++;
	parse_pos++;
	return 1;	
	}
	else if(strcasecmp(M[parse_pos],"<>") == 0)
	{
		// strcpy(prod[prod_pos]," OP -> <> ");
		// prod_pos++;
	parse_pos++;
	return 1;	
	}
	else
	{
	return 0;
	}
}
int word_ops()
{
	if(strcasecmp(M[parse_pos],"IN") == 0)
	{
		strcpy(prod[prod_pos]," word_ops -> IN ");
		prod_pos++;
	parse_pos++;
	return 1;	
	}
	else if(strcasecmp(M[parse_pos],"BETWEEN") == 0)
	{
		strcpy(prod[prod_pos]," word_ops -> BETWEEN ");
		prod_pos++;
	parse_pos++;
	return 1;	
	}
	else
	{
	return 0;
	}
}


int VAL()
{
	if(strcasecmp(M[parse_pos],"VAL") == 0)
	{
		parse_pos++;
		return 1;
	}
	else
	{
		return 0;
	}
}


void main()
{
char S[200],Str[200],T[20],*token,dlm[2]=" ";
int i,j,k;
char temp,buffer;
char error[][200]={"",
		"DROP TABLE <tablename>;",
		"ALTER TABLE <tablename> DROP COLUMN <column name> ; OR ALTER TABLE <tablename> ADD <column name> (<column description>) ;",
		"DELETE FROM <tablename> WHERE <condition> ;",
		"INSERT INTO <tablename> ( ... ) VALUES ( ... val|string ) ;",
		"",
		"CREATE TABLE <tablename> (<table attributes>) ;",
		"SELECT <column/s> FROM <table/s> WHERE <condition> ;",
		"",
		"UPDATE <tablename> SET <attr1=val1,..> WHERE <condition> ;",
		""
	};


top:
//old code start

S[0] = '\0';
Str[0] = '\0';

//initializing the flag array

for(i = 0; i<=10 ; i++)
{
	flag[i] = 0;
}

//initialising the prod matrix
for(i=0;i<50;i++)
{
	strcpy(prod[i],"\0");
}
prod_pos = 0;

printf("-------------------------------------\n");
printf("Type below:\n");
while(1)
{
	scanf("%s",T);
	//getchar();
	strcat(S," ");
	strcat(S,T);
	
	if(T[strlen(T)-1]==';')
	{
		break;	
	}

	if(strcmp(T,";")==0)
	{
		break;
	}
	if(strcmp(T,"exit")==0)
	{
		exit(0);
	}
}

//added padding
for(i=0,j=0;S[i]!='\0';i++,j++)
{
	if(
	(S[i]=='<')&&(S[i+1]=='=')||
	(S[i]=='>')&&(S[i+1]=='=')||
	(S[i]=='<')&&(S[i+1]=='>')||
	(S[i]=='!')&&(S[i+1]=='=')
	)
	{	
		Str[j]=' ';
		Str[j+1]=S[i];
		Str[j+2]=S[i+1];
		Str[j+3]=' ';
		j+=3;
		i++;
	}
	else if(
		(S[i]=='=')||
		(S[i]=='>')||
		(S[i]=='<')||
		(S[i]=='!')||
		(S[i]==';')||
		(S[i]=='(')||
		(S[i]==')')||
		(S[i]==',')		
		)
	{
		Str[j]=' ';
		Str[j+1]=S[i];
		Str[j+2]=' ';
		j+=2;
			
	}
	else
	{
		Str[j]=S[i];	
	}
}
Str[j]='\0';


//finished padding
//printf("\nWe entered:%s\n",Str);

token = strtok(Str,dlm);
strcpy(M[0],token);
//printf("%s\n",M[0]);

i=1;
while( token != NULL ) 
{
	//printf( "%d : %s\n",i, token );
    
	token = strtok(NULL,dlm);
	//if(strcmp(token,NULL)==0)
	if(token==NULL)
	break;
	strcpy(M[i],token);
	//printf("Saving to index %d\n", i);
	i++;
	//printf(" %d ",i);
}


//printf("Stored in Matrix\n");
strcpy(M[i],"\0");

//debug tokeniser

//This classifies the tokens and prints them in order of appearance with proper classification.

// printf("........................................\n");
// printf("|| TOKEN ....................... TYPE ||\n");
// printf("........................................\n");

int is_error = NO;


for(i=0;strcmp(M[i],"\0")!=0;i++)
{
	//printf("%s\n",M[i] );
	k = selector(M[i]);
	//printf("At position %d we have %d type token : %s\n",i,k,M[i]);
	if(k==1)
	{
		//printf(" %s ......................... KEYWORD\n",M[i]);
	}
	else if(k==2)
	{
		//printf(" %s ......................... OPERATOR\n",M[i]);
	}
	else if(k==3)
	{
		//printf(" %s ......................... SPECIAL SYMBOL\n",M[i]);
	}
	else if(k==4)
	{
		strcpy(M[i],"val");
		//printf(" %s ......................... VALUE\n",M[i]);
	}
	else if(k==5)
	{
		strcpy(M[i],"id");
		//printf(" %s ......................... IDENTIFIER\n",M[i]);
	}
	else if(k==6)
	{
		strcpy(M[i],"string");
		//printf(" %s ......................... string\n",M[i]);

	}
	else
	{
		is_error = YES;
		//printf(" %s ......................... ERROR\n",M[i]);
	}
}

if(is_error == YES)
{
	printf("There were errors in lexical analysis.\n");
}
else
{
	//Display token string that will be parsed
	printf("The tokens made are as follows:\n");
	for(i=0;strcmp(M[i],"\0")!=0;i++)
	{
		printf("%s ",M[i]);
		//printf("Token no %d : %s\n",i+1,M[i]);

	}
	M_length = i;
	printf("\n");
}

//-------------------------------------------------------
//Lexical analysis ends here. Syntactical analysis starts
//-------------------------------------------------------

//Start_State -> Pi start state
//P1 -> DROP TABLE id;
//P2 -> ALTER TABLE id DROP COLUMN id ;
//P3 -> DELETE FROM id WHERE <condition> ;
//P4 -> INSERT INTO id ( ... ) VALUES ( ... val|string ) ;
//P5 -> INSERT INTO id VALUES ( ... val|string ) ;
//P6 -> CREATE TABLE ...
//P7 -> SELECT <query> WITH NESTED
//P8 -> ALTER TABLE id ADD ENTRY ; 
//P9 -> UPDATE id SET attr1=val1,.... WHERE <condition> 

parse_pos = 0;

int success = Start_State();

if(success == YES)
{
	printf("Accepted by parser.\n");
}
else
{
	printf("Rejected by parser.\n");
	//to print expected syntax
	for(i=1;i<10;i++){
		if(flag[i]==YES){
			printf("Expected syntax format: %s\n",error[i]);
			break;
		}
	}
}

//Print the prod matrix
int last = 0;
if(success == YES)
{
	for(i=0;strcmp(prod[i],"\0")!=0;i++);
	last = i-1;

	printf("The parse is as follows:\n");
	int c_id=0;
	for(i = last; i >= 0 ; i--)
	{
		if((strcmp(prod[i]," BR_V -> ) VALUES ( ") == 0)&&(strcmp(prod[i-1]," BR_V -> ) VALUES ( ") == 0))
		{
			printf("%s\n",prod[i] );
			break;
		}
		if((strcmp(prod[i]," ID_LIST -> null ") == 0) || (strcmp(prod[i]," COL_LIST1 -> * ") == 0))
			c_id++;


		printf("%s\n",prod[i] );
		if(c_id==2)
			break;
	}
	
}
//Cleaning the matrix for next parse
//printf("Cleaning matrix\n");
for(i=0;strcmp(M[i],"\0")!=0;i++)
{
	strcpy(M[i],"\0");
}

goto top;
//old code ends
}