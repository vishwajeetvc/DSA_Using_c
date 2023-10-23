 // circular queue using array
#include <stdio.h>
#include <stdlib.h>
#define N 10 

int Queue[N];
int front = -1;
int rear = -1;

// queue methods
void enq(int);
void deq(int);
void display(int);
void peek(int);

int main(){
	void (*fn[4])(int) = {enq, deq, display,peek};
	while(1){
		int ch;
		printf("0.Enqueue  1.Dequeue  2.Display  3.Peek: ");
		scanf("%d",&ch);
		if(ch == 0){
			int data;
			printf("Enter the data : ");
			scanf("%d",&data);
			fn[ch](data);
		} else {
			fn[ch](0);
		}
		int more;
		printf("\nMore ? : ");
		scanf("%d",&more);
		if(!more) break;
	}
	return 0;
}
void peek(int x){
	if(front == -1 && rear == -1){
		printf("Queue is empty");
	} else {
		printf("%d",Queue[front]);
	}
}
void display(int x){
	if(front == -1 && rear == -1){
		printf("Queue is empty");
	} else{
		for(int i = front ; i < rear+1;i++){
			printf("%d ",Queue[i]);
		}
	}
}
void deq(int x){
	if(front == -1 && rear == -1){
		printf("Queue is empty");
	} else if(front == rear){
		front = rear = -1;
	} else {
		front++;
	}
}
void enq(int x){
	if(front == -1 && rear == -1){
		front = rear = 0;
		Queue[rear] = x;
	} else if ((rear+1)%N == front){
		printf("Queue is full.");
	} else {
		rear = (rear+1)%N;
		Queue[rear] = x;
	}
}

