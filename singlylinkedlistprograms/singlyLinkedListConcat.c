#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void create(struct Node**);
void display(struct Node *);
int displayMenu();
void concat(struct Node **,struct Node*,struct Node*);
int main(){
    int c;
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    struct Node *concatList=NULL;
    do{
        c=displayMenu();
        switch (c)
        {
        case 1:
            create(&head1);
            break;
        case 2:
            display(head1);
            break;
        case 3:
            create(&head2);
            break;
        case 4:
            display(head2);
            break;
        case 5:
            concat(&concatList,head1,head2);
            break;
        case 999:
            break;
        default:
            printf("Enter valid choice\n");
        }
    }while(c!=999);
    return 0;
}
int displayMenu(){
    int c;
    printf("Please choose one of the following\n");
    printf("1.Add to list 1\n");
    printf("2.Display list 1\n");
    printf("3.Add to list 2\n");
    printf("4.Display list 2\n");
    printf("5.Concat\n");
    printf("999.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&c);
    return c;
}
void create(struct Node** head){
    int ele;
    struct Node *newNode;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the number to be added to list\n");
    scanf("%d",&ele);
    newNode->data=ele;
    newNode->next=NULL;
    if(*head==NULL){
       *head=newNode;
    }else{
        struct Node *temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
    }
}
void display(struct Node *head){
    struct Node *temp=head;
    if(head==NULL){
        printf("No element in the list\n");
        return;
    } 
    printf("Element in the list are :\n");
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void concat(struct Node** concatList,struct Node* head1,struct Node* head2){
    *concatList=head1;
    struct Node* temp=*concatList;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
    display(*concatList);
}