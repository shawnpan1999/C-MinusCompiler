%{
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <stdarg.h>
  #include "Struct.h"
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
  extern int yylex (void);
  void yyerror (char const *s);
  int insertVar(char *scope, char *name, char type);
  int insertFunc(char *name, struct Var *argHead, char *rType, int start);
  void callVar(char *name, char *funcName);
  void varMatch();
  void callFunc(char *name);
  void init();


  struct L* makelist(int quad);
  struct L* merge(struct L* p1, struct L* p2);
  void backpatch(struct L* list, int quad);
  int lex(FILE* fp);
  int emit(char *type, char *arg1, char *arg2, char *res);
  char *newTemp();
  int isFunc(int i);
  void myPrint(struct Word* w_look);
 struct Var* gHead = NULL;
 struct Function* fHead = NULL;
 struct L* lHead;
 struct Word* head;
 extern struct Stack stack;
 extern struct Queue queue;

 extern struct FunOut funOut[100];
 int funNum = 0;
 int mainNum = 0;
 int inC = 0;
 int eip = 100;
 int start = 0;
 int end = 0;
 int tempNum = 0;
 int j = 0;
 int TEMP[1000];
  char funcName[200] = "\0";
  char buffer1[200];
  char buffer2[200];
  char buffer3[200];
  char buffer4[200];
%}

%debug

%union {
    struct L{
        int k;
        char op[20];
        char op1[20];
        char op2[20];
        char res[30];
        struct L *next;
        struct L *true;
        struct L *false;
    };

    struct Var *var;
    struct L  l;
    double value;
    char strval[2000];
    int subtok;
    int quad;
}


/* Bison declarations.  */
%start program
%token LE "<="
%token GE ">="
%token EQ "=="
%token NE "!="
%token AND "&&"
%token OR "||"
%token NOT "!"
%token IF
%token ELSE
%token WHILE
%token INT
%token VOID
%token RETURN
%token <strval>  NUM
%token <strval> ID
%left '-' '+'
%left '*' '/' '%'
%right '='
%left NEG     /* negation--unary minus */ /* 负号 */
%right '^'    /* expressiononentiation */ /* 幂运算 */


%type <l> simple-expression expression expression-stmt statement N selection-stmt iteration-stmt c-statement
%type <strval>   additive-expression  factor term  call var-list 
%type <strval> var-declaration fun-declaration type-specifier mulop addop relop declaration local-declarations var
%type <var> params param-list  param
%type <quad> M 


%% /* The grammar follows.  */ /*　下面是语法 */
program:   declaration-list {printf("*******************************this is a program\n");}
;

declaration-list: declaration-list declaration
        | declaration 
        ;

declaration: var-declaration
        | fun-declaration
        ;

var-declaration: type-specifier var-list ';'
        ;

var-list: var-list ',' ID {
                if(funcName[0] !='\0' ) {
                strcpy($$, funcName);
            } else {
                strcpy($$, "global");
            }
            insertVar($$, $3, 'b');
        }
        | var-list ',' ID '[' NUM ']'{
            if(funcName[0] !='\0' ) {
                strcpy($$, funcName);
            } else {
                strcpy($$, "global");
            }
            insertVar($$, $3, 'a');
        }
        | ID{
                if(funcName[0] !='\0' ) {
                    strcpy($$, funcName);
                } else {
                    strcpy($$, "global");
                }
                insertVar($$, $1, 'b');
            }
        | ID '[' NUM ']' {
                        if(funcName[0] !='\0' ) {
                            strcpy($$, funcName);
                        } else {
                            strcpy($$, "global");
                        }
                        insertVar($$, $1, 'a');
                    }
        ;








type-specifier: INT {strcpy($$,"INT"); }
        | VOID {strcpy($$,"VOID"); } 
        ;

fun-declaration: type-specifier ID '(' {
                    funOut[funNum].lines = eip;
                    strcpy(funOut[funNum++].name, $2);
                    strcpy(funcName, $2);
                    if(!strcmp("main", funcName)) {
                        mainNum = eip;
                    }
                    start = eip;
                    }
                params ')' compound-stmt {
                end = eip;
                /* insertFunc */
                insertFunc($2, $5, $1, start);
                struct Var* temp = $5;
                memset(funcName, 0, sizeof(funcName));
                //insertFunc()
             }
        ;

params: param-list {$$ = $1;}
        | VOID {$$=NULL;}
        | /* empty */ {$$=NULL;}
        ;



param-list:  param-list ',' param {
            $$ = $1;
            struct Var* temp = $$;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = $3;
        }
        | param {$$ = $1;}
        ;

param: type-specifier ID {
            $$ = (struct Var*)malloc(sizeof(struct Var));
            strcpy($$->scope, funcName);
            strcpy($$->name, $2);
            $$->type = 'b';
            $$->next = NULL;
            insertVar(funcName, $2, 'b');
        }
        | type-specifier ID '[' ']'{
            $$ = (struct Var*)malloc(sizeof(struct Var));
            strcpy($$->scope, funcName);
            strcpy($$->name, $2);
            $$->type = 'a';
            $$->next = NULL;
            insertVar(funcName, $2, 'a');
        }
        ;

compound-stmt: '{' local-declarations statement-list '}'
        ;

local-declarations: /* empty */
        | local-declarations var-declaration {
                if(funcName[0] !='\0' ) {
                    strcpy($2, funcName);
                } else {
                    strcpy($2, "global");
                }
            }
        ;

statement-list: /* empty */
        | statement-list statement
        ;


statement: expression-stmt  {
                $$.k = $1.k;
                strcpy($$.op, $1.op);
                strcpy($$.op1, $1.op1);
                strcpy($$.op2, $1.op2);
                strcpy($$.res, $1.res);
                $$.next = $1.next;
                $$.true = $1.true;
                $$.false = $1.false;
                 ;
        }
        | compound-stmt      
        | selection-stmt 
        | iteration-stmt 
        | return-stmt 
        ;

expression-stmt: expression ';' {
                $$.k = $1.k;
                strcpy($$.op, $1.op);
                strcpy($$.op1, $1.op1);
                strcpy($$.op2, $1.op2);
                strcpy($$.res, $1.res);
                $$.next = $1.next;
                $$.true = $1.true;
                $$.false = $1.false;
                 ;
        }
        | ';' 
        ;


c-statement: statement {
                $$.k = $1.k;
                strcpy($$.op, $1.op);
                strcpy($$.op1, $1.op1);
                strcpy($$.op2, $1.op2);
                strcpy($$.res, $1.res);
                $$.next = $1.next;
                $$.true = $1.true;
                $$.false = $1.false;
                 ;
            }
        | '{' statement-list '}'
        ;

selection-stmt: {inC=1;} IF '(' expression ')'{inC=0;} M c-statement N ELSE M c-statement M{
                backpatch($4.true, $7);
                backpatch($4.false, $11);
                backpatch($9.next, $13);
                $$.next = merge($8.next, $9.next);
                $$.next = merge($$.next, $12.next);
            }
            ;


M:       /*empty*/ {$$ = eip;}
        ;

N:       /*empty*/ {
                $$.next = makelist(eip);
                emit("j","-", "-", "-");
                }
        ;

selection-stmt: {inC = 1;} IF '(' expression ')' {inC = 0;}  M   statement {
                backpatch($4.true, $7);
                $$.next = merge($4.false, $8.next);
            }
        ;



iteration-stmt: {inC = 1;} WHILE '(' M expression ')' {inC = 0;} M statement M{
                backpatch($9.next, $4);
                backpatch($5.true, $8);
                $$.next = $5.false;
                itoa($4, buffer1, 10);
                emit("j", "-", "-", buffer1);
                backpatch($5.false, $10+1);
                memset(buffer1, 0, sizeof(buffer1));
            }

        ;




return-stmt: RETURN ';'  { 
            emit("ret", "-", "-", "None");
            emit("pop", "-", "-", "eip");
            }
        | RETURN expression ';' {
            emit("=", $2.res, "-", "eax");
            emit("ret", "-", "-", "eax");
            emit("pop", "-", "-", "eip");
            //stack.val[top--];
            }
        ;

expression: var '=' expression  {
                callVar($1, funcName);
                $$.k = $3.k;
                strcpy($$.op, "=");
                strcpy($$.op1, $3.res);
                strcpy($$.op2, "-");
                strcpy($$.res, $1);
                $$.next = $3.next;
                $$.true = $3.true;
                $$.false = $3.false;
                emit("=", $3.res, "-",$1);
                }
        | simple-expression  {
                $$.k = $1.k;
                strcpy($$.op, $1.op);
                strcpy($$.op1, $1.op1);
                strcpy($$.op2, $1.op2);
                strcpy($$.res, $1.res);
                $$.next = $1.next;
                $$.true = $1.true;
                $$.false = $1.false;
                }
        ;

var:    ID {strcpy($$, $1); }
        | ID '[' expression ']' {
            strcpy(buffer3, $1);
            strcat(buffer3, "[");
            strcat(buffer3, $3.res);
            strcat(buffer3, "]");
            strcpy($$, buffer3);
            memset(buffer3, 0, sizeof(buffer3));
        }
        ;

simple-expression: additive-expression relop additive-expression {
                $$.true = makelist(eip);
                $$.false = makelist(eip+1);
                buffer1[0] = 'j';
                strcat(buffer1, $2);
                emit(buffer1, $1, $3, "0");
                memset(buffer1, 0, sizeof(buffer1));
                emit("j", "-", "-", "0");
            }
        | simple-expression OR M simple-expression {
                backpatch($1.false, $3);
                $$.true = merge($1.true, $4.true);
                $$.false = $4.false;
                strcpy($$.res, newTemp());
                memset(buffer2, 0, sizeof(buffer2));
            }
        | simple-expression AND M simple-expression {
                backpatch($1.true, $3);
                $$.false = merge($1.false, $4.false);
                $$.true = $4.true;
                strcpy($$.res, newTemp());
                memset(buffer2, 0, sizeof(buffer2));
            }
        | NOT simple-expression {
                $$.true = $2.false;
                $$.false = $2.true;
                strcpy($$.res, $2.res);
            }
        | '(' simple-expression ')' {
                $$.true = $2.true;
                $$.false = $2.false;
                strcpy($$.res, $2.res);
        }
        | additive-expression {
                if(inC == 1) {
                        $$.true = makelist(eip);
                        $$.false = makelist(eip+1);
                        strcpy($$.res, $1);
                        emit("jnz", $1, "-", "0");
                        emit("j", "-", "-", "0");
                } else {
                        strcpy($$.res, newTemp());
                        memset(buffer2, 0, sizeof(buffer2));
                        emit("=", $1, "-", $$.res);
                }
            }
        ;


relop:  "<=" {strcpy($$, "<=");}
        | '<' {strcpy($$, "<"); }
        | '>' {strcpy($$, ">"); }
        | ">=" {strcpy($$, ">="); }
        | "==" {strcpy($$, "==");}
        | "!=" {strcpy($$, "!="); }
        ;

additive-expression: additive-expression addop term {
            if (!strcmp($1, "empty"))
            {
                strcpy($$, newTemp());
                memset(buffer2, 0, sizeof(buffer2));
                emit($2, "0", $3, $$);
            } else {
                strcpy($$, newTemp());
                memset(buffer2, 0, sizeof(buffer2));
                emit($2, $1, $3, $$);
            }
        }
        | term {strcpy($$,$1); }
        | /* empty */ {strcpy($$, "empty");}
        ;

addop:    '+' {strcpy($$, "+"); }
        | '-' {strcpy($$, "-"); }
        ;

term: term mulop factor {
            strcpy($$, newTemp());
            emit($2, $1, $3, $$);
            memset(buffer2, 0, sizeof(buffer1));
        }
        | factor {strcpy($$,$1);}
        ;

mulop:   '*' {strcpy($$, "*"); }
        | '/' {strcpy($$, "/"); }
        ;

factor: '(' expression ')' { strcpy($$,$2.res); }
        | var {callVar($1, funcName);strcpy($$, $1);}
        | call  {callFunc($1);queue.end=0; strcpy($$, "eax");}
        | NUM {strcpy($$, $1); }
        ;

call: ID '(' args ')' {
                strcpy($$, $1);
                int i = queue.front;
                for(; i < queue.end; i++) {
                    emit("par", "-", "-", queue.val[i]);
                }
                emit("push", "-", "-", "eip+1");
                //queue.end = 0;
                //printf("eip+1 is %d\n", eip+1);
                //stack.val[stack.top++] = (eip+1);
                emit("call", "-", "-", $1);
            }
        ;

args:     /* empty */
        | arg-list
        ;

arg-list: arg-list ',' expression {
                 queue.val[queue.end++] = $3.res; 
                 }
        | expression {
            queue.front = queue.end = 0;
            queue.val[queue.end++] = $1.res;
            }
        ;

%%
void yyerror (char const *s) {
    fprintf (stderr, "%s/n", s);
}

int insertVar(char *scope, char *name, char type) {
    struct Var* temp = gHead;
    struct Var* t2 = temp;
    while(temp) {
        if(!strcmp(temp->name, name)){
            if(!strcmp(temp->scope, scope)) {
                printf(" \'%s\' Redefinition error\n", name);
                return 0;
            }
        }
        t2 = temp;
        temp = temp->next;
    }
    struct Var* newVar = (struct Var*)malloc(sizeof(struct Var));
    strcpy(newVar->scope, scope);
    strcpy(newVar->name, name);
    newVar->type = type;
    newVar->next = NULL;
    if(gHead == NULL) {
        gHead = newVar;
    } else {
        t2->next = newVar;
    }
    return 1;
}


void init() {
    lHead = (struct L*)malloc(200 * sizeof(struct L));
    int i;
    for(i = 100; i < 200; i++) {
        lHead[i].k = 0;
        memset(lHead[i].op, 0, sizeof(lHead[i].op));
        memset(lHead[i].op1, 0, sizeof(lHead[i].op1));
        memset(lHead[i].op2, 0, sizeof(lHead[i].op2));
        memset(lHead[i].res, 0, sizeof(lHead[i].res));
        lHead[i].next = NULL;
        lHead[i].true = NULL;
        lHead[i].false = NULL;
    }
}

struct L* makelist(int quad) {

    return &lHead[quad];
}

struct L* merge(struct L* p1, struct L* p2) {
    struct L* temp = p1;
    if(p1 == NULL) {
        return p2;
    }
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = p2;
     ;
    return p1;
}


void backpatch(struct L* list, int quad) {
    struct L* temp = list;
    itoa(quad, buffer1, 10);
    while(temp) {
        strcpy(temp->res, buffer1);
        temp = temp->next;
    }
    memset(buffer1, 0, sizeof(buffer1));
}


int emit(char *type, char *arg1, char *arg2, char *res) {
    printf("%d:\t (%s, %s, %s, %s)\n", eip, type, arg1, arg2, res);
    strcpy(lHead[eip].op, type);
    strcpy(lHead[eip].op1, arg1);
    strcpy(lHead[eip].op2, arg2);
    strcpy(lHead[eip].res, res);
    eip++;
    return 1;
}

char *newTemp() {
    buffer2[0] = 'T';
    itoa(tempNum, buffer1, 10);
    strcat(buffer2, buffer1);
    tempNum++;
    memset(buffer1, 0, sizeof(buffer1));
    return buffer2;
}

int isFunc(int i) { //判断第i行第i个四元式是否是某个函数的开始位置
    for(j = 0; j < funNum; j++) {
        if(i == funOut[j].lines)
            return 1;
    }
    return 0;
}


void myPrint(struct Word* w_look) {
	printf("\n===================Lex Result===================\n");
	w_look = head;
	printf("WordNumber     WordLine       WordName       WordMark\n");
	while (w_look) {
        printf(" %d\t\t%d\t\t%s\t\t%c\n", w_look->num, w_look->line, w_look->name, w_look->mark_name);
		w_look = w_look->next;
	}
}

int insertFunc(char *name, struct Var *argHead, char *rType, int start) {
    struct Function* temp = fHead;
    struct Function* t2 = temp;
    while(temp) {
        if(!strcmp(temp->name, name)){
            printf(" \'%s\' Redefinition error\n", name);
            return 0;
        }
        t2 = temp;
        temp = temp->next;
    }
    struct Function* newVar = (struct Function*)malloc(sizeof(struct Function));
    strcpy(newVar->name, name);
    newVar->argHead = argHead;
    strcpy(newVar->rType,rType);
    newVar->qStartLabel = start;
    newVar->next = NULL;
    if(fHead == NULL) {
        fHead = newVar;
    } else {
        t2->next = newVar;
    }
    return 1;
}

void callVar(char *name, char *funcName) {
    struct Var* temp = gHead;
    while(temp) {
        if(!strcmp(name, temp->name)) {
            return;
        }
        temp = temp->next;
    }
    printf("Var %s isn't difined.\n", name);
}

void callFunc(char *name) {
    struct Function* temp = fHead;
    while(temp) {
        if(!strcmp(name, temp->name)) {
            int num = 0;
            struct Var* t2 = temp->argHead;
            while(t2) {
                num++;
                t2=t2->next;
            }
            if(num == queue.end) {
                return;
            } else {
                printf("arguement number's isn't matched\n");
                return;
            }
        }
        temp = temp->next;
    }
    printf("%s function isn't defined!\n", name);
}

int main(int argc, const char *args[]) {
     //   yydebug = 1;
    //static struct L lHead[1000];
     init();
    extern FILE *yyin;
    char document[50] = "li.txt";
	if(argc > 1 && (yyin = fopen(document, "rt")) == NULL) {
		fprintf(stderr, "can not open %s\n", args[1]);
		exit(1);
	}
	if(yyparse()) {
		exit(-1);
	}
    myPrint(head);
    int i = 100;
    for(i = 100; i < eip; i++) {
        if(i == mainNum) {
            printf("Program Begin at :\n");
        } else if(isFunc(i)) {
            printf("%s Begin at :\n", funOut[j].name);
        }
        printf("\t %d:\t (%s, %s, %s, %s)\n", i, lHead[i].op, lHead[i].op1, lHead[i].op2, lHead[i].res);
    }
    printf("\t %d:\t \n", eip);

    while(gHead) {
        printf("%s\t%s\t%c\n", gHead->scope, gHead->name, gHead->type);
        gHead = gHead->next;
    }
    printf("******************************\n");
    while(fHead) {
        printf("%s\t%s\t\n", fHead->name, fHead->rType);
        while(fHead->argHead) {
            printf("name is %s    scope is %s   type is %c\n", fHead->argHead->name, fHead->argHead->scope, fHead->argHead->type);
            fHead->argHead = fHead->argHead->next;
        }
        fHead = fHead->next;
    }
    return 0;
}