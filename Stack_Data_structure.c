#include<stdio.h>
#include<stdlib.h>
#define MAX 10

int stack[MAX];
int top = -1;;

void pop();
void push();
void display();

int main(){

    int choise;
    while(1){
        system("clear");
        printf("\t1.Push\t2.Pop\t3.Display\t4.Exit : ");
        scanf("%d", &choise);
        switch(choise){
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(1);
                break;
            default:
                printf("Invalid");
                break;

        }
    }
    return 0;
}
void push(){
    if(top == MAX - 1){
        printf("Stack is full");
    } else {
        int num;
        top++;
        printf("\n\tEnter you value : ");
        scanf("%d", &num);
        stack[top] = num;
    }
}
void display(){
    printf("\n");
    for(int i = 0; i <=top; i++){
        printf("%d ", stack[i]);
    }
    printf("\n");
}
void pop(){
    if(top == -1){
        printf("\nStack is already empty : ");
    } else {
        top--;
    }
}


