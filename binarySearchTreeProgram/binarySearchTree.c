#include<stdio.h>
#include<stdlib.h>
typedef struct BST{
    struct BST *left;
    struct BST *right;
    int data;
}Node;
int displayMenu();
void insert(Node *root,Node *temp);
void preorder(Node *root);
void postorder(Node *root);
void inorder(Node *root);
Node* create();
int main(){
    int c;
    Node *root=NULL;
    do{
        c=displayMenu();
        Node *temp;
        switch (c)
        {
        case 1:
            temp=create();
            if(root==NULL)
                root=temp;
            else
                insert(root,temp);
            break;
        case 2:
            if(root==NULL)
                printf("Tree is empty\n");
            else{
                preorder(root);
                printf("\n");      
            }
            break;
        case 3:
            if(root==NULL)
                printf("Tree is empty\n");
            else{
                postorder(root);
                printf("\n");
            }
            break;   
        case 4:
            if(root==NULL)
                printf("Tree is empty\n");
            else{
                inorder(root);
                printf("\n");
            }   
            break;
        case 999:
            break;
        default:
            printf("Enter the valid input\n");
        }
    }while(c!=999);
    return 0;
}
int displayMenu(){
    int c;
    printf("Enter your choice\n");
    printf("1.Add element to tree\n");
    printf("2.Pre-order Traversal\n");
    printf("3.Post-order Traversal\n");
    printf("4.In-order Traversal\n");
    printf("999.Exit\n");
    scanf("%d",&c);
    return c;
}
Node* create(){
    Node *newNode=(Node *)malloc(sizeof(Node));
    newNode->left=NULL;
    newNode->right=NULL;
    printf("Enter the data to be inserted in node of the tree\n");
    scanf("%d",&newNode->data);
    return newNode;
}
void insert(Node *root,Node *temp){
    if(root->data>temp->data){
        if(root->left==NULL)
            root->left=temp;
        else
            insert(root->left,temp);
    }else{
        if(root->right==NULL)
            root->right=temp;
        else
            insert(root->right,temp);    
    }
}
void preorder(Node *root){
    if(root!=NULL){
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
    
}
void postorder(Node *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d\t",root->data);
    }
    
}
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
    
}