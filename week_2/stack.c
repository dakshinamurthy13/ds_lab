#include<stdio.h>
#define max 5
int top=-1;
int displayMenu();
void push(int stack[]);
void pop(int stack[]);
void display(int stack[]);
int main(){
    int c,stack[max];
    do{
        c= displayMenu();
        switch (c)
        {
        case 1:
            push(stack);
            break;
        case 2:
            pop(stack);
            break;
        case 3:
            display(stack);
            break;
        case 4:
            break;
        default:
            printf("Please enter valid input\n");
        }
    }while(c!=4);
    return 0;
}
void push(int stack[]){
    int ele;
    if(top==max-1)
        printf("Stack Overflow\n");
    else{
        top++;
        printf("Enter the new element to be entered to stack\n");
        scanf("%d",&ele);
        stack[top]=ele;
    }
}
void pop(int stack[]){
    int ele;
    if(top==-1)
        printf("Stack UnderFlow!\n");
    else{
        ele=stack[top];
        top--;
        printf("The popped element is %d\n",ele);
    } 
}
void display(int stack[]){
    int i;
    if(top==-1)
        printf("The stack is empty\n");
    else{
        printf("The elements in the stack are:\n");
        for(i=0;i<=top;i++)
            printf("%d\t",stack[i]);
        printf("\n");
    }
}
int displayMenu(){
    int c;
    printf("Please choose one of the following\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display Stack\n");
    printf("4. Exit\n");
    scanf("%d",&c);
    return c;
}