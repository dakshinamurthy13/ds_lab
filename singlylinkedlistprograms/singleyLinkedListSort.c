#include <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void create(struct Node **head);
void display();
int displayMenu();
void sort(struct Node **head);
void delete(struct Node **head,int ele);
void addToSort(struct Node **head,int ele);
int main(){
    struct Node *head=NULL;
    int c;
    do{
        c=displayMenu();
        switch (c)
        {
        case 1:
            create(&head);
            break;
        case 2:
            display(head);
            break;
        case 3:
            sort(&head);
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
    printf("1.Add to list\n");
    printf("2.Display list\n");
    printf("3.Sort list ascending\n");
    printf("999.Exit\n");
    printf("Enter your choice\n");
    scanf("%d",&c);
    return c;
}
void create(struct Node **head){
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
void sort(struct Node **head){
    struct Node *temp=*head,*sortList=NULL;
    if(temp==NULL){
        printf("List is empty.Cant sort!\n");
        return;
    }
    int count=0,i=0;
    while(temp!=NULL){
        count++;
        temp=temp->next;
    }
    temp=*head;
    for(i=0;i<count;i++){
        int smallest=temp->data;
        do{
            if(smallest>temp->data)
                smallest=temp->data;
            temp=temp->next;
        }while(temp!=NULL);
        printf("Smallest in list is %d\n",smallest);
        printf("The sorted list is \n");
        delete(head,smallest);
        addToSort(&sortList,smallest);
        temp=*head;
    }
    display(sortList);
    *head=sortList;
}
void delete(struct Node **head,int ele){
    struct Node *temp=*head,*found=NULL;
    if(temp->data==ele){
        printf("Element %d is deleted \n",ele);
        *head=temp->next;
        return;
    }
    while(temp->next!=NULL){
        if(temp->next->data==ele){
            found=temp->next;
            break;
        }
        temp=temp->next;
    }
    if(found==NULL){
        printf("Element not found\n");
        return;
    }
    temp->next=found->next;
    free(found);
    printf("Element %d is deleted \n",ele);
}
void addToSort(struct Node **head,int ele){
    struct Node *newNode,*temp=*head;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=ele;
    newNode->next=NULL;
    if(temp==NULL){
        *head=newNode;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}