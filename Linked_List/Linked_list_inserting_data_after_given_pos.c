#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *next;
} Node;

int main(){

    Node *newNode, *head, *temp;
    head = NULL;

    while(1){
        // creating and filling node
        newNode = (Node*)malloc(sizeof(Node));
        printf("Enter data : ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        // playing with pointer
        if(head == NULL){ head = temp = newNode; }
        else {
            temp->next = newNode;
            temp = newNode;
        }
        int choise;
        printf("Want some more : ");
        scanf("%d", &choise);
        if(!choise)break;
    }

    // printing the linked list
    temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

    // inserting data after given positoin
    int pos;
    int count = 1, data;
    printf("Enter the position : ");
    scanf("%d", &pos);
    temp = head;
    while(count < pos){
        temp = temp->next;
        count++;
    }
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data : ");
    scanf("%d", &newNode->data);
    newNode->next = temp->next;
    temp->next = newNode;

    // printing the linked list
    temp = head;
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    // realising the memory
    Node * node;
    temp = head;
    while(temp != NULL){
        node = temp;
        temp = temp->next;
        free(node);
    }

}








