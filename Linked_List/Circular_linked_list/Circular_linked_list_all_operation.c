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

// get the element from index, takes index no and tail ptr.
int get_from(int ele, Node * tail);

// delete from beginning , takes tail pointer.
void del_beg(Node*);

// delete from end , takes tail pointer.
void del_end(Node**);

// delete at given position , takes tail pointer.
void del_at(int, Node*);

// reverse the circular lkd, takes reference pointer.
void reverse(Node**);
int main(){
    Node *tail = crtlkd();
    // prtlkd(tail);
    // ins_beg(tail);
    // prtlkd(tail);
    // ins_end(&tail);
    // prtlkd(tail);
    // ins_at(3,tail);
    // prtlkd(tail);
    // printf("%d",get_from(3,tail));
    // del_beg(tail);
    // printf("\n");
    // del_end(&tail);
    // del_at(3, tail); 
    prtlkd(tail);
    printf("\n");
    reverse(&tail);
    printf("\n");
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
    int index = 0;
    Node * temp = tail->next;
    while(index < pos-2){ // (pos-2) because we have to approach (pos-1) node. for appropriate addresses.
       temp = temp->next; 
       index++;
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    printf("\n   Enter the data : ");
    scanf("%d",&newNode->data);

    newNode->next = temp->next;
    temp->next = newNode;

}
int get_from(int index, Node * tail){
    int count = 0;
    while(count < index){
        tail = tail->next;
        count++;
    }
    return tail->data;
}
void del_beg(Node*tail){
    Node *node;
    node = tail->next;
    tail->next = tail->next->next;
    free(node);

}
void del_end(Node**tail){
    Node *node = *tail;
    Node *temp = (*tail)->next;
    while(temp->next != *tail){
        temp = temp->next;
    }
    temp->next = (*tail)->next;
    free(node);
    *tail = temp;
}
void del_at(int pos, Node*tail){
    int count = 0;
    tail=tail->next;
    while(count < pos -2){
        tail = tail->next;
        count++;
    }
    Node*node = tail->next;
    tail->next = tail->next->next;
    free(node);
    
}
void reverse(Node**tail){
    Node*midprt,*preptr,*nextptr;

    // for changing the tail, 
    Node*_ = (*tail)->next;
    
    preptr = (*tail)->next;
    midprt = preptr->next;
    nextptr = midprt->next;

    preptr->next = *tail;

    while(midprt != *tail){
        midprt->next = preptr;
        preptr = midprt;
        midprt = nextptr;
        if(nextptr!= *tail){
            nextptr = nextptr->next;
        } else {
            nextptr = NULL;
        }
    }
    midprt->next = preptr;
    // changing the tail.
    *tail = _;
}
