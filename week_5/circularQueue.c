#include<stdio.h>
#define MAX 3
int front=-1;
int rear=-1;
void enqueue(int queue[]);
int dequeue(int queue[]);
void displayQueue(int queue[]);
int displayMenu();
int main(){
    int c,ele;
    int queue[MAX];
    do{
        c=displayMenu();
        switch (c)
        {
        case 1:
            enqueue(queue);
            break;
        case 2:
            ele=dequeue(queue);
            if(ele!=-1)
                printf("The dequeued element is %d\n",ele);
            break;
        case 3:
            displayQueue(queue);
            break;
        case 4:
            break;
        default:
            printf("Enter vaild choice\n");
        }
    }while(c!=4);
}
int displayMenu(){
    int n;
    printf("Please choose one of the following\n");
    printf("1.Add to queue\n");
    printf("2.Remove from Queue\n");
    printf("3.Display Queue\n");
    printf("4.Exit\n");
    scanf("%d",&n);
    return n;
}
void enqueue(int queue[]){
    if((front==0&&rear==MAX-1)||(front==rear+1))
        printf("Queue full\n");
    else{
        int ele;
        printf("Enter the number to be queued\n");
        rear=(rear+1)%MAX;
        if(front==-1)
            front++;
        scanf("%d",&ele);
        queue[rear]=ele;
    }
}
int dequeue(int queue[]){
    if(front==-1 && rear==-1){
        printf("Queue empty\n");
        return -1;
    }else{
        int ele=queue[front];
        if(front==rear){
            front=-1;
            rear=-1;
        }else
            front=(front+1)%MAX;
        return ele;
    }
}
void displayQueue(int queue[]){
    if(front==-1 && rear==-1)
        printf("Queue empty\n");
    else{
        int i=front;
        printf("The elements of the queue are :\n");
        do{
            printf("%d\t",queue[i]);
            i=(i+1)%MAX;
        }while(i!=(rear+1)%MAX);    
        printf("\n");
    }
}