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

        // sec(1) filling the node with data and address of next Node;
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter Date : ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;

        // sec(1) playing with pointer
        if(head == NULL) {
            head = temp = newNode; 
        } else {
            temp->next = newNode;
            temp = newNode;
        }

        // sec(2) terminator
        int more;
        printf("Want some more: ");
        scanf("%d",&more);
        if(more == 0){
            break;
        }
    }

    // sec(3) printing and realeasing the memory;
    // temp = head;
    // while(temp != NULL){
    //     Node * temp2;
    //     temp2 = temp;
    //     printf("%d ", temp->data);
    //     temp = temp->next;
    //     free(temp2);
    // }


    // error if sec(3) is uncommented 
    // printing the linked list
    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }


    // ==============THE Code=====================//
    //============================================//
    // error if sec(3) is uncommented 
    // inserting at the end
       // traversing to last node
        temp = head;
        while(temp->next != NULL){
            temp= temp->next; 
        }
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter Date : ");
        scanf("%d",&newNode->data);

        temp->next = newNode;
        newNode->next = NULL;
        
    //============================================//

    // error if sec(3) is uncommented 
    // printing the linked list
    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
        newNode->next = NULL;
    }

}
