#include<stdio.h>
#include<stdlib.h>

// creates node
typedef struct node{
    int data;
    struct node * next;
} Node;

// create a linked list.
Node *lkd();

// print linked list
void printlkd(Node *head);

// free linked list
void freelkd(Node *head);

// inserts element at the beginning
void ins_beg(Node **head);

// inserts element at the end
void ins_end(Node **head);

// inserts element after the given postion
void ins_af(int pos, Node *head);

// deletes element from the beginning
void del_beg(Node **head);

// deletes element from the beginning
void del_end(Node *head);

// deletes element after given position
void del_at(int pos, Node *head);

// find the length of linked list (iterative)
int lenthof(Node *head);

// reversing the linked list
void reverse(Node**head);

int main(){
    Node * head = lkd();
    printlkd(head);
    // printf("\nThe length of lkd is %d\n",lenthof(head));

    // ins_beg(&head);
    
    // ins_end(&head);

    // int pos;
    // printf("Enter a position: ");
    // scanf("%d",&pos);
    // ins_af(pos,head);

    // del_end(head);
    
    // del_beg(&head);

    // int pos;
    // printf("Enter a position: ");
    // scanf("%d",&pos);
    // del_at(pos,head);
    
    reverse(&head);
    printlkd(head);
    freelkd(head);
}

Node *lkd(){
    Node *head, *newNode, *temp;
    head = NULL;
    while(1){
        // creating and filling a node
        newNode = (Node*)malloc(sizeof(Node));
        printf("Enter the data : ");
        scanf("%d",&newNode->data);
        newNode->next = NULL;

        // managing pointer
        if(head == NULL) head = temp = newNode;
        else {
            temp->next = newNode;
            temp = newNode;
        }
        // Asking for more data or Not
        int choise;
        printf("Want some more 0.No 1.Yes : ");
        scanf("%d",&choise);
        if(!choise) break;
    }
    return head;
}
void printlkd(Node *temp){
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    printf("\n\n");
}
void freelkd(Node *temp){
    Node * node;
    while(temp != NULL){
        node = temp;
        temp = temp->next;
        free(node);
    }
}
void ins_beg(Node **head){
    // creating node and filing
    Node*newNode;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data to insert at the beginning : ");
    scanf("%d",&newNode->data);

    // managing pointer 
    newNode->next = *head;
    *head = newNode;
}
void ins_end(Node **head){

    // creating node and filling the data and null at the next
    Node*newNode, *temp;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data to insert at the End : ");
    scanf("%d",&newNode->data);
    newNode->next = NULL;

    // reaching to last node
    temp = *head;
    while(temp->next != NULL){
        temp = temp->next;
    }

    // managing the pointer
    temp->next = newNode;
}
void ins_af(int pos, Node *head){

    // creating node and filling the data 
    Node*newNode, *temp;
    newNode = (Node *)malloc(sizeof(Node));
    printf("Enter the data to insert after given Position : ");
    scanf("%d",&newNode->data);

    // reaching to pos
    int counter = 1;
    temp = head;
    while(counter < pos){
        temp = temp->next;
        counter++;
    }
    // managing pointers
    newNode->next = temp->next;
    temp->next = newNode;

}
void del_beg(Node **head){
    Node *temp;
    temp = *head;
    *head = (*head)->next;
    free(temp);
}
void del_end(Node *head){
    Node *temp = head;
    while((temp->next)->next != NULL){
        temp = temp->next;
    }
    free((temp->next));
    temp->next = NULL;
}
void del_at(int pos, Node *head){
    int count = 1;
    Node *temp = head;
    while( count < pos ){
        temp = temp->next;
        count++;
    }
    Node *garbage = temp->next;
    temp->next = garbage->next;
    free(garbage);
}
int lenthof(Node *head){
    int count = 0;
    Node * temp = head;
    while(temp != NULL) {
        temp=temp->next;
        count++;
    }
    return count;
}
void reverse(Node**head){
    Node *prevtemp, *nexttemp;

    prevtemp = *head;
    *head = (*head)->next;
    nexttemp = (*head)->next;
    prevtemp->next = NULL;

    while(1){
        (*head)->next = prevtemp;

        prevtemp = *head;
        *head = nexttemp;

        if(nexttemp->next == NULL){
            nexttemp->next = prevtemp;
            break;
        } else {
            nexttemp = nexttemp->next;
        }
    }
}
