#include<stdio.h>
#include<stdlib.h>

// #pragma pack(1)
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node; 

// Creates a doubly linked,
// takes reference of head ptr and return tail pointer.
Node * crtlk(Node **head);

// Displays a linked list (singly or doubly)
// takes head ptr,
void display(Node *head);

// Release the memory, takes head pointer.
void freee(Node*head);

// Insert data at the beginning,
// takes reference of head pointer.
void ins_beg(Node**head);

// Insert data at the end,
// takes tail ptr of doubly linked list.
void ins_end(Node**end);

// Insert data after given position,
// takes head ptr.
void ins_af(int,Node*head);

// Delete from beginning, takes reference of head ptr.
void del_beg(Node **head);

// Delete from end, takes reference of tail prt.
void del_end(Node **end);

// Delete after given position, takes head ptr.
void del_af(int,Node *head);

int main(){
     Node *head, *end = crtlk(&head);
     // printf("%d ",end->data);
     display(head);
    // ins_beg(&head);
    //
    // ins_end(&end);
    //
    // ins_af(2, head);
    // display(head);
     
    // del_beg(&head);
    del_end(&end);
    // del_af(3,head);
    display(head);
    // printf("%lu",sizeof(Node));
    // freee(head);
}
void display(Node *head){
    // You know here we used call by value 
    while(head!=NULL){
        // displaying the data of the  node
        printf("%d ",head->data);
        head=head->next;
    }
    printf("\n");
}
Node *crtlk(Node **head){
    Node *temp, *newNode;
    *head = NULL;

    while(1){
        // creating node and filling data
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter the data : ");
        scanf("%d",&newNode->data);
        newNode->prev = NULL;
        newNode->next = NULL;

        // playing with pointer
        if(*head == NULL){
            *head = temp = newNode;
        } else {
            temp->next = newNode;
            newNode->prev = temp;
            temp = newNode;
        }

        // asking for more nodes 
        int choise;
        printf("Want some more : ");
        scanf("%d",&choise);
        if(!choise) break;
    }
    return temp;
}
void freee(Node*temp){
    Node * node = temp;
    while(temp!=NULL){
        node = temp;
        temp=temp->next;
        free(node);
    }
}
void ins_beg(Node**head){
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data: ");
    scanf("%d",&newNode->data);
    newNode->next = *head;
    *head = newNode;
}
void ins_end(Node**temp){

    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data: ");
    scanf("%d",&newNode->data);
    (*temp)->next = newNode;
    newNode->prev = *temp;
}
void ins_af(int pos,Node*head){
    // creating and filling node
    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data: ");
    scanf("%d",&newNode->data);

    // playing with pointers
    int count = 1;
    while(count < pos){
        head = head->next;
        count++;
    }
    newNode->next = head->next;
    head->next = newNode;
}
void del_beg(Node **head){
    Node *temp = *head;
    *head = (*head)->next;
    free(temp);
}
void del_end(Node **end){
    Node *temp = *end;
    ((*end)->prev)->next = NULL;
    free(temp);
}
void del_af(int pos,Node *head){
    int count = 0;
    while(count < pos){
        head=head->next;
        count++;
    }
    Node *temp = head;
    (head->prev)->next = head->next;
    free(temp);
}
