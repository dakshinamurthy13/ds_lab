#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void enqueue(struct Node **front,struct Node **rear);
void dequeue(struct Node **front,struct Node **rear);
void displayQueue(struct Node *front);
int displayMenu();
int main(){
    struct Node *front=NULL,*rear=NULL;
    int c;
    do
    {
        c=displayMenu();
        switch (c)
        {
        case 1:
            enqueue(&front,&rear);
            break;
        case 2:
            dequeue(&front,&rear);
            break;
        case 3:
            displayQueue(front);
            break;
        case 999:
            break;
        default:
            printf("Enter valid input");
        }
    } while (c!=999);
    return 0;
}
int displayMenu(){
    int c;
    printf("Please choose one of the following\n");
    printf("1.Add to Queue\n");
    printf("2.Remove from queue\n");
    printf("3.Display Queue\n");
    printf("999.Exit\n");
    scanf("%d",&c);
    return c;
}
void enqueue(struct Node **front,struct Node **rear){
    struct Node *newNode;
    int ele;
    newNode=(struct Node *)malloc(sizeof(struct Node));
    printf("Enter the value to be queued\n");
    scanf("%d",&ele);
    newNode->data=ele;
    newNode->next=NULL;
    if((*rear)==NULL){
        *rear=newNode;
        *front=newNode;
        printf("Entered element is %d\n",(*front)->data);
    }else{
        (*rear)->next=newNode;
        (*rear)=newNode;
    }
}
void dequeue(struct Node **front,struct Node **rear){
    if((*front)==NULL){
        printf("The queue is empty\n");
        return;
    }else{
        printf("The element removed from the queue is %d\n",(*front)->data);
        struct Node *secondInQueue=(*front)->next;
        free(front);
        (*front)=secondInQueue;
        if((*front)==NULL)
            (*rear)=NULL;
    }
}
void displayQueue(struct Node *front){
    struct Node *temp;
    temp=front;
    if(front==NULL){
        printf("Queue Empty\n");
        return;
    }else{
        printf("Elements in queue are \n"); 
        while(temp!=NULL){
            printf("%d\t",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}