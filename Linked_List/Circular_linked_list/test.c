#include<stdio.h>
#include<stdlib.h>

typedef struct _{
    int data;
    struct _*next;
}Node;

// create circular linked list, returns tail ptr.
Node *crtlkd();

// prints linked list, takes tail ptr.
void prtlkd(Node*);

// free the memory occupied by circular lkd, takes tail ptr.
void freee(Node*);

// insert node at the begining, takes tail ptr.
void ins_beg(Node*);

// insert node at the end, takes tail ptr.
void ins_end(Node**);

// insert node at the given pos, takes tail ptr.
void ins_at(int,Node*);

int main(){
    Node *tail = crtlkd();
    prtlkd(tail);
    ins_beg(tail);
    prtlkd(tail);
    ins_end(&tail);
    prtlkd(tail);
    freee(tail);
}
Node *crtlkd(){
    Node *newNode,*tail;
    tail = NULL;
    while(1){
        // creating node and filling it.
        newNode = (Node*)malloc(sizeof(Node));
        printf("Enter the data : ");
        scanf("%d",&newNode->data);

        if(tail == NULL){
            newNode->next = newNode;
        } else {
            newNode->next = tail->next;
            tail->next = newNode;
        }
        // moving tail forward
        tail = newNode;

        // asking for more element.
        int ch;
        printf("Want some more : ");
        scanf("%d",&ch);
        if(!ch) break;
     }
    return tail;
}
void prtlkd(Node*tail){
    Node *temp ;
    temp = tail->next;
    while(temp != tail) {
        printf("%d \n",temp->data);
        temp = temp->next;
    }
    printf("%d",temp->data);
}
void freee(Node*tail){
    Node *temp, *head = tail->next;
    temp = head;
    Node *node;
    while(temp->next != head){
        node = temp;
        temp = temp->next;
        free(node);
    }
    free(temp);
}
void ins_beg(Node*tail){
    Node *newNode;

    newNode = (Node*)malloc(sizeof(Node));
    printf("\n   Enter the data : ");
    scanf("%d",&newNode->data);

    newNode->next = tail->next;
    tail->next = newNode;
}
void ins_end(Node**tail){
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1); // Exit the program or handle the error appropriately
    }

    printf("\n   Enter the data : ");
    scanf("%d",&newNode->data);

    if(*tail == NULL){
        newNode->next = newNode;
    } else{
        newNode->next = (*tail)->next;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}
void ins_at(int pos,Node*tail){
    int index = 1;
    Node * temp = tail->next;

    while(index < pos-1){
       temp = temp->next; 
       index++;
    }

}
