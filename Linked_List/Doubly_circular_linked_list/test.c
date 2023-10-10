#include<stdio.h>
#include<stdlib.h>

typedef struct _ {
    int data;
    struct _ *next;
    struct _ *prev;
} Node;

// create doubly circular linked list, returns head ptr;
Node *crtCirDouLkd();

// printf the doubly circular linked list, takes head ptr.
void prtCirDouLkd(Node *);

// freee the doubly circular linked list
void freee(Node *);

// insert a node at the beginning, takes ref of head ptr.
void ins_beg(Node **);

// insert a node at the end of the doubly circular linked list, takes head ptr.
void ins_end(Node *);

// insert a node at given position in circular linked list, takes head ptr.
void ins_at(int,Node *);

// delete at the beginning, takes ref of head ptr.
void del_beg(Node **);

// delete at the end, takes head ptr.
void del_end(Node *);

// delete the node at the given position, takes head ptr.
void del_at(int, Node*);

int main(){
    Node *head = crtCirDouLkd();
    // ins_beg(&head);
    // ins_end(head);
    // ins_at(2,head);
    // del_beg(&head);
    // del_end(head);
    del_at(2,head);

    prtCirDouLkd(head);

    freee(head);
    // prtCirDouLkd(head);
}
void del_at(int pos, Node*head){
    int count = 0;
    Node *temp = head;
    while(count < pos-2){
        temp=temp->next;
        count++;
    }
    Node *node = temp->next;
    temp->next->next->prev = temp;
    temp->next = temp->next->next;
    free(node);
}
void del_end(Node *head){
    Node *node = head->prev;
    ((head->prev)->prev)->next = head;
    (head->prev) = (head->prev)->prev;
    free(node);
}
void del_beg(Node **head){
    Node *node = *head;
    (*head)->prev->next = (*head)->next;
    (*head)->next->prev = (*head)->prev;
    *head = (*head)->next;

    free(node);
}
void ins_at(int pos,Node *head){
    if(pos == 1){
        ins_beg(&head);
    } else {
        int count = 0; 
        Node *temp = head;
        while(count < pos-2){
            temp = temp->next;
            count++;
        }

        Node *newNode;
        newNode = (Node *) malloc (sizeof(Node));
        printf("Enter the data : ");
        scanf("%d",&newNode->data);

        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;

    }
}
void ins_end(Node *head){
    Node *newNode;
    newNode = (Node *) malloc (sizeof(Node));
    printf("Enter the data : ");
    scanf("%d",&newNode->data);
    
    (head->prev)->next = newNode;
    newNode->prev = (head)->prev;
    newNode->next = head;
    (head)->prev = newNode;

}
void ins_beg(Node **head){
    Node *newNode;
    newNode = (Node *) malloc (sizeof(Node));
    printf("Enter the data : ");
    scanf("%d",&newNode->data);

    ((*head)->prev)->next = newNode;
    newNode->prev = (*head)->prev;
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;

}
void freee(Node *head){
    if (head == NULL) {
        return; // Handle the case of an empty list
    }
    Node*temp = head->next;
    Node *node;
    while(temp != head){
        node = temp;
        temp = temp->next;
        free(node);
    }
}
void prtCirDouLkd(Node *head){
    Node *temp = head;
    while(temp->next != head){
        printf("%d \n",temp->data);
        temp=temp->next;
    }
    printf("%d \n",temp->data);
}
Node *crtCirDouLkd(){
    Node *newNode, *head, *temp;
    head = NULL;
    while(1){
        newNode = (Node *) malloc (sizeof(Node));
        printf("Enter the data : ");
        scanf("%d",&newNode->data);
        if(head == NULL){
            head = temp= newNode;
            head->next = head;
            head->prev = head;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            newNode -> next = head;
            head->prev = newNode;
            temp = newNode;
        }

        int ch;
        printf("Want some more : ");
        scanf("%d",&ch);
        if(!ch) break;

    }
    return head;
}
