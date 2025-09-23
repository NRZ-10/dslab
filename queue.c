#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1,rear = -1;

void enqueue(int value){
	if(rear == MAX-1){
		printf("Queue overflow! \n");
	}
	else{
		if(front == -1)front=0;
		rear++;
		queue[rear] = value;
		printf("%d inserted into the queue \n", value);
	

	}
}

void dequeue(){
	if(front == -1 || front > rear){
		printf("Queue underflow! \n");
	}
	else{
		printf("%d deleted from the queue \n", queue[front]);
		front++;
	}
}
void display(){
	if(front == -1 || front > rear){
		printf("Queue is empty \n");
	}
	else{
		printf("Queue elements:  ");
		for(int i=front;i<rear;i++){
			printf("%d",queue[i]);
		}
		printf("\n");
	}
}
int main(){
	int choice,value;
	while(1){
		printf("\n-----Queue Menu-----\n");
		printf("1. Enqueue \n");
		printf("2. Dequeue \n");
		printf("3. Display \n");
		printf("4. Exit \n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){

			case 1:
				printf("Enter value to insert: ");
				scanf("%d",&value);
				enqueue(value);
				break;

			case 2:
				dequeue();
				break;

			case 3:
				display();
				break;

			case 4:
				exit(0);

			default:
				printf("Invalid choice! \n");
		}
	}
	return 0;
}

