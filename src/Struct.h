

struct Var {
    double val;
    char  name[200];
    //a: 数组   b:单个变量
    char  type;
    long length;
    //作用域
    char  scope[200];
    struct Var* next;
};

struct Function {
    char name[200];
    struct Var* localHead;
    struct Var* argHead;
    char rType[20];
    int  funLength;
    int  qStartLabel;
    int  qEndLabel;
    int  qReturnLabel;
    struct Function *next;
};

struct Compound
{
    struct Function* selfFunc;
    int start;
    int end;
};


struct Stack {
    int val[2000];
    int base;
    int top;
}stack;

struct Queue {
    char *val[2000];
    int front;
    int end;
}queue;

struct FunOut
{
    int lines;
    char name[30];
}funOut[100];



