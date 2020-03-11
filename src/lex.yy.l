%option noyywrap yylineno
%{
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "test.tab.h"
//|[A-Z]|[_]|[a-zA-Z_][a-zA-Z_0-9]*
struct Word // 单词表结构体: 单词名字、标识类型、状态、序号、行号、连接符号表指针、连接下一结点指针
{
	char name[20];
	char mark_name;
	int state;
	int num;
	int line;
	struct Sign* link;
	struct Word* next;
};
extern struct Word *head;
struct Word *last;
int L_row = 1;
%}

NUM [1-9][0-9]*|[0]



ID [a-zA-Z_][a-zA-Z_0-9]*

SEMI [;]
COMMA [,]
ASSIGNOP [=]

RELOP [>]|[<]|[>][=]|[<][=]|[=][=]|[!][=]
AND [&][&]
OR [|][|]
NOT [!]

PLUS [+]
MINUS [-]
STAR [*]
DIV [/]


DOT [.]


TYPE int|void
MAIN [m][a][i][n]
LP \(
RP \)
LB \[
RB \]
LC \{
RC \}

COMMENT \/\*(?:[^\*]|\*+[^\/\*])*\*+\/
COMMENT2 \/\/.*

RETURN return
IF if
ELSE else 
WHILE while



SPACE [ \n\t]
/*end of definition*/

%%
{AND} {return AND;}
{OR} {return OR;}
{NOT} {return NOT;}
{MAIN} {
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;
		head->line = L_row;
		head->mark_name = 'm';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);
		temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = 'm';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	strcpy(yylval.strval,yytext);
	return ID;
}

{SEMI} {
    if(head == NULL) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = ';';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = ';';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return ';';
}

{COMMA} {
    if(head == NULL) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = ',';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = ',';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return ',';
}
{ASSIGNOP} {
    if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = '=';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = '=';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return '=';
}

{NUM} {
    if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = 'n';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = 'n';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	strcpy(yylval.strval,yytext);
	return NUM;
}

{PLUS} {
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = '+';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = '+';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return '+';
}

{MINUS} {
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = '-';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = '-';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return '-';
}

{DIV} {
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = '/';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = '/';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return '/';
}


{STAR} {
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = '*';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = '*';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return '*';
}

{RELOP} {
	char c='\0';
	if(!strcmp(yytext, ">")) {
		c = '>';
	} else if (!strcmp(yytext, "<") ){
		c = '<';
	} else if (!strcmp(yytext, ">=") ){
		c = 'g';
	} else if (!strcmp(yytext, "<=") ){
		c = 'u';
	} else if (!strcmp(yytext, "==") ){
		c = '#';
	} else if (!strcmp(yytext,"&&" ) ){
		c=  '&';
	} else if (!strcmp(yytext,"||" ) ){
		c=  '|';
	} else if (!strcmp(yytext,"!" ) ){
		c=  '!';
	}
	 else { 
		c = '@';
	}
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = c;
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = c;
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	if(c == '<' || c == '>') {
		return c;
	} else {
		if (c == 'g') {
			return GE;
		} else if (c == 'u') {
			return LE;
		} else if (c == '#') {
			return EQ;
		} else if (c == '&') {
			return AND;
		} else if (c == '|') {
			return OR;
		} else if (c == '!') {
			return c;
		}
		else {
			return NE;
		}
	}
}

{DOT} {
    //printf("get a dot: %s\n", yytext);
}



{RETURN} {
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = 'r';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = 'r';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return RETURN;
}
{IF} {
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = 'f';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = 'f';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return IF;
}

{ELSE} {
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = 'e';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = 'e';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return ELSE;
}

{WHILE} {
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = 'w';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = 'w';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return WHILE;
}

{TYPE} {
	char c;
	if(!strcmp(yytext, "void")) {
		c = 'v';
	} else {
		c = 'a';
	}
    if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = c;
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = c;
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	if (c == 'v') {
		return VOID;
	} else {
		return INT;
	}
}

{LP} |
{RP} |
{LB} |
{RB} |
{LC} |
{RC} {
    char c;
	if(!strcmp(yytext, "(")) {
		c = '(';
	} else if(!strcmp(yytext, ")")) {
		c = ')';
	} else if(!strcmp(yytext, "[")){
		c='[';
	}else if(!strcmp(yytext, "]")) {
		c = ']';
	} else if(!strcmp(yytext, "{")){
		c='{';
	}else{
		c='}';
	}
	
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = c;
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = c;
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	return c;
}

{SPACE} {
	if(!strcmp(yytext, "\n")) {
		L_row++;
	} 
/*ABANDON THESE CHARACTORS*/
}

{ID} {
	if(!head) {
		head = (struct Word *)malloc(sizeof(struct Word));
		strcpy(head->name, yytext);
		head->num = 0;head->line = L_row;
		head->mark_name = 'i';
		head->next = NULL;
		last = head;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	} else {
		struct Word* temp = (struct Word *)malloc(sizeof(struct Word));
		last->next = temp;
		strcpy(temp->name, yytext);temp->line = L_row;
		temp->num = last->num+1;
		temp->mark_name = 'i';
		temp->next = NULL;
		last = temp;
		//printf("name is %s,  mark_name is %c\n", last->name, last->mark_name);
	}
	strcpy(yylval.strval,yytext);
	return ID;
}


{COMMENT} { }
{COMMENT2} { }


%%

/*
int lex(FILE* fp) {
	//printf("In lex\n");
	yyin = fp;
	system("pause");
	while (yylex());
	system("pause");
    return 0;

	extern FILE *yyin;
}
*/