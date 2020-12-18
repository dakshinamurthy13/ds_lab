#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *previous;
    struct Node *next;
};
struct Node *head;
int displayMenu();
void create();
void display();
void delete();
void insertAtPosition();
int main(){
    int c;
    do{
        c=displayMenu();
        switch (c)
        {
        case 1:
            create();
            break;
        case 2:
            display();
            break;
        case 3:
            delete();
            break;
        case 4:
            insertAtPosition();
            break;
        case 999:
            break;
        default:
            printf("Enter vaild input");
        }
    }while(c!=999);
}
int displayMenu(){
    int c;
    printf("Please choose one of the following\n");
    printf("1.Add to list\n");
    printf("2.Display list\n");
    printf("3.Delete from list\n");
    printf("4.Insert at specific position\n");
    printf("999.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&c);
    return c;
}
void create(){
    int ele;
    struct Node *newNode,*temp;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the element\n");
    scanf("%d",&ele);
    newNode->data=ele;
    newNode->next=NULL;
    if(head==NULL){
        newNode->previous=NULL;
        head=newNode;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    newNode->previous=temp;
    temp->next=newNode;
}
void display(){
    if(head==NULL){
        printf("No elements in array\n");
        return;
    }
    struct Node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
void delete(){
    if(head==NULL){
        printf("No elements in array\n");
        return;
    }
    int ele;
    printf("Enter the element to be deleted\n");
    scanf("%d",&ele);
    struct Node *temp=head,*found=NULL;
    if(temp->data==ele){
        printf("The element %d has been deleted\n",temp->data);
        head=temp->next;
        head->previous=NULL;
        return;
    }
    while(temp->next!=NULL){
        if(temp->data==ele){
            found=temp;
            break;
        }
        temp=temp->next;
    }
    if(found==NULL){
        printf("Enter element %d not in list\n",ele);
        return;
    }
    printf("The element %d has been deleted\n",found->data);
    temp=found->previous;
    temp->next=found->next;
    found->next->previous=temp;
    free(found);
}
void insertAtPosition(){
    int pos,count=0,i=0;
    struct Node *temp=head,*before,*after;
    printf("Enter the position\n");
    scanf("%d",&pos);
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    if(pos>count){
        printf("Invalid Position\n");
        return;
    }
    printf("Enter the element\n");
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    scanf("%d",&newNode->data);
    temp=head;
    if(pos==0){             //Insert at first location
        if(head!=NULL){
            newNode->next=head;
            newNode->previous=NULL;
            head->previous=newNode;
            head=newNode;
        }else{
            newNode->next=NULL;
            newNode->previous=NULL;
            head=newNode;
        }
        printf("Element %d is successfully inserted at position 0\n",newNode->data);
        return;
    }else if(pos==count){         //If we want to insert at last location
        while (temp->next!=NULL){
            temp=temp->next;
        }
        newNode->next=NULL;
        newNode->previous=temp;
        temp->next=newNode;
        return;
    }
    temp=head;
    for(i=0;i<pos;i++){
        if(i==pos-1){
            before=temp;
            after=temp->next;
            break;
        }
        temp=temp->next;
    }
    newNode->previous=before;
    newNode->next=after;
    before->next=newNode;
    after->previous=newNode;
    printf("Element %d is successfully inserted at position %d\n",newNode->data,pos);
}