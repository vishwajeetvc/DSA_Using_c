#include<stdio.h>
#include<stdlib.h>

// #pragma pack(1)
typedef struct node{
    int data;
    struct node *next;
    struct node *prev;
}Node; 

// creates a doubly linked list
Node * crtlk();

// displays a linked list (singly or doubly)
void display(Node *head);

// release the memory
void freee(Node*head);

// insert data at the beginning
void ins_beg(Node**head);

// insert data at the end
void ins_end(Node*head);

// insert data after given position
void ins_af(int,Node*head);

// delete from beginning
void del_beg(Node **head);

// delete from end
void del_end(Node *head);

// delete after given position
void del_af(int,Node *head);


int main(){
     Node *head = crtlk();
     display(head);
    // ins_beg(&head);
    //
    // ins_end(head);
    //
    // ins_af(2, head);
    // display(head);
     
    // del_beg(&head);
    // del_end(head);
    del_af(3,head);
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
Node * crtlk(){
    Node *head, *temp, *newNode;
    head = NULL;

    while(1){
        // creating node and filling data
        newNode = (Node *)malloc(sizeof(Node));
        printf("Enter the data : ");
        scanf("%d",&newNode->data);
        newNode->prev = NULL;
        newNode->next = NULL;

        // playing with pointer
        if(head == NULL){
            head = temp = newNode;
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
    return head;
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
void ins_end(Node*temp){

    Node *newNode;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data: ");
    scanf("%d",&newNode->data);

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
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
void del_end(Node *head){
    while(head->next != NULL){
        head = head->next;
    }

    Node *temp = head;
    (head->prev)->next = NULL;
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
