#include<stdio.h>

#define N 10
int stack[N];
int top =-1;

// push(insert) a data into stack, takes data(int);
void push(int);

// pop(delete) a data from the stack(top most);
void pop();

// peek(return the top most element);
void peek();

// display
void display();

int main(){
    void (*operation[4])() = {push,pop,peek,display};
    while(1){
        int op;
        printf("\n0. Push  1.Pop  2.Peek   3.Display : "); 
        scanf("%d", &op);
        operation[op]();
    }

}
void display(){
    for(int i = 0; i <= top; i++){
        printf("%d ",stack[i]);
    }
}
void peek(){
    if(top == -1){
        printf("Stack is empty!");
    } else{
        printf("%d ", stack[top]);
    }
    printf("\n");
}
void pop(){
    if(top == -1){
        printf("Underflow: ");
    } else {
        int x =  stack[top];
        top--;
        printf("%d ", x);
    }
}
void push(int x){
    if(top == N - 1){
        printf("Overflow!");
    } else {
        printf("Enter the data : ");
        scanf("%d",&x);
        top++;
        stack[top] = x;
    }
}
