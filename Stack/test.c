#include<stdio.h>
#include<stdlib.h>

typedef struct _{
    int data;
    struct _ *next;
} Node ;

// taking a empty stack
Node * top = NULL;

// insert a node on the top.
void push(int num);

// display all element.
void display();

// delete whole stack.
void del_stack();

// delete the top most element.
void pop();

// print the top most element.
void peek();

// print the length of the stack.
void length();

int main(){
    push(1);
    push(2);
    push(3);
    pop();
    push(5);
    // display();
    // peek();
    length();
    del_stack();
}
void length(){
    Node *temp = top;
    int count = 0;
    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    printf(" length = %d", count);
}
void peek(){
    printf("%d ",top->data);
}
void pop(){
    Node *node;
    node= top;
    top = top->next;
    free(node);
}
void del_stack(){
    Node *node = top;
    if(node == NULL){
        printf("UnderFlow");
    } else {
        while(top!=NULL){
            node = top;
            top=top->next;
            free(node);
        } 
    }
}
void display(){
    Node *temp = top;
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->next;
    }
    return;
}
void push(int num){
    Node *newNode;
    newNode = (Node *) malloc(sizeof(Node));
    if(newNode == NULL){
        printf("System failed to allocate memory");
        return;
    }
    newNode->data = num;
    newNode->next = top;;
    top = newNode;
    return;
}

