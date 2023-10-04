#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *next;
} Node;

Node * createll();
void printlkd(Node *);
void freell(Node *);
void ins_beg(Node **);

int main(){
    Node *head, *newNode, *temp;
    head = createll();
    printlkd(head);
    // inserting element at beginning
    ins_beg(&head);

    printlkd(head);
    // freeing the memory
    freell(head);
    
    return 0;
}

void ins_beg(Node ** head){
    Node*temp,*newNode;
    temp = *head;
    newNode = (Node *) malloc (sizeof(Node));
    printf("Enter the data : ");
    scanf("%d",&newNode->data);
    newNode->next = temp;
    *head = newNode;
}

void printlkd(Node *head){
    // printing the linked list
    Node * temp;
    temp = head;

    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}
void freell(Node *head){
    Node *node,*temp;
    temp = head;
    while(temp!=NULL){
        node = temp;
        temp = temp->next;
        free(node);
    }
}

Node * createll(){
    Node *head, *newNode, *temp;
    head = NULL;
    while(1){

        // creating the node and filling it.
        newNode = (Node *) malloc (sizeof(Node));
        printf("Enter the data : ");
        scanf("%d",&newNode->data);
        newNode->next =  NULL;

        // playing with pointers
        if(head == NULL) head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }

        // asking for more elements
        int choise;
        printf("Want some more : ");
        scanf("%d",&choise);
        if(!choise)break;
    }
    return head;
}

