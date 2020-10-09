#include<stdio.h>
#include<string.h>
#define max 10
int top=-1;
void push(char stack[],char n);
char pop(char stack[]);
void inputExpression(char a[]);
void evalExpression(char a[],char p[],char stack[]);
void outputPostfix(char a[],char p[]);
int priority(char a);
int stackEmpty();
int main(){
    char stack[max];
    char a[15],p[15];
    inputExpression(a);
    evalExpression(a,p,stack);
    outputPostfix(a,p);
    return 0;
}
void push(char stack[],char n){
    if(top==max-1)
        printf("Stack Overflow\n");
    else{
        top++;
        stack[top]=n;
    }
}
char pop(char stack[]){
    char ele;
    if(top==-1)
        printf("Stack UnderFlow!\n");
    else{
        ele=stack[top];
        top--;
    } 
    return ele;
}
void inputExpression(char a[]){
    printf("Please enter the expression to be converted to postfix\n");
    fflush(stdin);
    gets(a);
}
void evalExpression(char a[],char p[],char stack[]){
    int i,pi=0,b;
    char ele;
    for(i=0;i<strlen(a);i++){
        if(a[i]>=48 && a[i]<=57 ||
                a[i]>=65 && a[i]<=90 ||
                a[i]>=97 && a[i]<=122
                )//If number add to postfix expression
        {
            p[pi]=a[i];
            pi++;
        }else if(a[i]==40)//If open bracket push to stack
        {
            push(stack,a[i]);
        }
        else if(a[i]==41)//If closed bracket pop all elements till open bracket
        {
            if(top!=-1){
                ele=pop(stack);
                while(ele!=40){
                    p[pi]=ele;
                    pi++;
                    ele=pop(stack);
                }
            }
        }
        else if(a[i]==42 || a[i]==47 || a[i]==43||a[i]==45 )
        {
            if(priority(a[i])<priority(stack[top])){
                do{
                    ele=pop(stack);
                    push(stack,a[i]);
                    p[pi]=ele;
                    pi++;
                }while(priority(a[i])>priority(stack[top]));
                
            }else{
                push(stack,a[i]);
            }
        }
        
    }
    if(stackEmpty()==-1){
        while(stackEmpty()!=1){
            p[pi]=pop(stack);
            pi++;
        }
    }
    p[pi]='\0';
}
int priority(char a){
    switch (a)
    {
    case '*':
    case '/':
        return 3;
    case '+':
    case '-':
        return 2;
    case '(':
        return 1;
    default:
        return 0;
    }
}
int stackEmpty(){
    if(top==-1)
        return 1;
    else
        return -1;
}
void outputPostfix(char a[],char p[]){
    printf("The input infix expression is: \n");
    puts(a);
    printf("The resultant postfix expression is\n ");
    puts(p);
}