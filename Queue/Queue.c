// queue using array.
#include<stdio.h>

#define N 5
int queue[N];

int front = -1;
int rear = -1;

void enqueue(int x);
void dequeue(int x);
void display(int x);
void peak(int x);

void sayhi(int x){
	printf("Hi");
}
int main(){

	void (*fn[4])(int) = {enqueue,dequeue,display,sayhi};
	while(1){
		int ch;
		printf("0.Enqueue  1.Dequeue  2.Display  3.sayHi: ");
		scanf("%d",&ch);

		// asking data to put in queue.
		if(ch == 0){
			int data;
			printf("Enter the data : ");
			scanf("%d", &data);
			fn[0](data);
		} else {
			fn[ch](0);
		}

		// asking for more operation
		int more;
		printf("\nWant some more operations : ");
		scanf("%d", &more);
		if(!more) break;

	}

}
void peak(int x){
	if(front == -1 && rear == -1){
		printf("Queue is empty");
	} else {
		printf("\nThe peek is %d.", queue[front]);
	}
}
void display(int x){
	if(front == -1 && rear == -1){
		printf("Queue is empty");
	} else {
		for(int i = front; i < rear+1; i++){
			printf("%d ",queue[i]);
		}
	}
}
void dequeue(int x){
	if(front == -1 && rear == -1){
		printf("\nUnderflow Condition");
	} else if( front == rear){
		front = rear = -1;
	} else {
		front++;
	}
}
void enqueue(int x){
	if(rear == N-1){
		printf("\nOverFlow");
	} else if((front == -1) && (rear == -1)){
		front = rear = 0;	
		queue[rear] = x;
	} else {
		rear++;
		queue[rear] = x;
	}
}
