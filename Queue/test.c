 // Queue using linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct _{
	int data;
	struct _ *next;
} Node ;

Node *front = NULL;
Node *rear = NULL;

// takes multiple data at once.
void enq();

// delete single data at once;
void deq();


void display();

int main(){
	while(1){
		void (*fn[3])()= {enq,deq,display};

		int ch;
		printf("\n0. Enqueue  1. Dequeue  2.Display : ");
		scanf("%d",&ch);
		fn[ch]();

	}
	return 0;
}
void display(){
	Node *temp = front;
	while(temp != NULL){
		printf("%d ", temp->data);
		temp = temp->next;
	}
}
void deq(){
	if(front== NULL){ 
		printf("\nUnderFlow");
		return;
	}
	Node *node = front;
	front = front->next;
	free(node);
}
void enq(){
	Node *newNode, *temp;
	while(1){
		newNode = (Node*)malloc(sizeof(Node));
		if(newNode == NULL) {
			printf("Failed to locate memory : ");
			return;
		}
		printf("Enter your data : ");
		scanf("%d",&newNode->data);
		newNode->next = NULL;

		if(front == NULL){
			front = temp = rear = newNode;
		} else {
			rear = newNode;
			temp->next = newNode;
			temp = newNode;
		}

		int more;
		printf("Want some more data? :");
		scanf("%d",&more);
		if(!more) break;
	}
}
