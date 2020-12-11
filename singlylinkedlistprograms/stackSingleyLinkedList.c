#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *previous;
};
struct Node *top=NULL;
void push();
void display();
int displayMenu();
void pop();
int main(){
    int c;
    do{
        c=displayMenu();
        switch (c)
        {
        case 1:
            push();
            break;
        case 2:
            display();
            break;
        case 3:
            pop();
            break;
        case 999:
            break;
        default:
            printf("Enter valid input\n");
        }
    }while(c!=999);
    return 0;
}
void push(){
    int ele;
    struct Node *newNode;
    printf("Enter the element to be inserted\n");
    scanf("%d",&ele);
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=ele;
    if(top==NULL){
        newNode->previous=NULL;
        top=newNode;
    }else{
        newNode->previous=top;
        top=newNode;
    }
}
void display(){
    struct Node *temp=top;
    if(top==NULL){
        printf("Stack Empty!!!\n");
        return;
    }
    printf("Elements in the stack are printed from top\n");
    while(temp!=NULL){
        printf("\t%d\n",temp->data);
        temp=temp->previous;
    }
}
int displayMenu(){
    int c;
    printf("Please choose one of the following\n");
    printf("1.Push to stack\n");
    printf("2.Display stack\n");
    printf("3.Pop stack\n");
    printf("999.Exit\n");
    scanf("%d",&c);
    return c;
}
void pop(){
    struct Node *temp=top;
    if(temp==NULL){
        printf("Stack empty!!\n");
        return;
    }
    top=temp->previous;
    printf("The popped element is %d\n",temp->data);
    free(temp);
}