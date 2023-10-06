/*
 
   Implementing the singly linked list
 
*/
#include<stdio.h>
#include<stdlib.h>

// creating node;
typedef struct Node{
    int data;
    struct Node *next;
} Node;

int main(){
    Node *head, *newNode, *temp;
    head = newNode = temp = NULL;

    while(1){

        // filling the node with data and address of next Node;
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter Date : ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;

        // playing with pointer
        if(head == NULL) {
            head = temp = newNode; 
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        // terminator
        int more;
        printf("Want some more: ");
        scanf("%d",&more);
        if(more == 0){
            break;
        }
    }

    // printing and realeasing the memory;
    temp = head;
    while(temp != NULL){
        Node * temp2;
        temp2 = temp;
        printf("%d ", temp->data);
        temp = temp->next;
        free(temp2);
    }

    // Below code will not work because memeory if freed.
    // temp = head;
    // while(temp != NULL){
    //     printf("%d ", temp->data);
    //     temp = temp->next;
    // }

}
