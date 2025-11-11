#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

int queue[SIZE];
int front=-1,rear=-1;

void enqueue(int value){
        if((front == 0 && rear == SIZE-1) || (rear+1 == front)){
                printf("Queue is FULL.\n");
        }else{
                if(front == -1)
                        front=0;
                rear=(rear+1) % SIZE;
                queue[rear]=value;
                printf("%d inserted into the queue.\n");
                }
}

void dequeue(){
        if(front == -1){
                printf("Queue is EMPTY.\n");
        }else{
                int value=queue[front];
                if(front == rear){
                        front=rear=-1;
        }else{
                front=(front+1) % SIZE;
        }
        printf("%d deleted from the queue.\n",value);
        }
}

void display(){
        if(front == -1){
                printf("Queue is EMPTY.\n");
        }else{
                printf("Queue elements are: ");
                int i=front;
                while(1){
                        printf("%d ",queue[i]);
                        if(i == rear)
                                break;
                        i=(i+1)%SIZE;
                }
                printf("\n");
        }
}

int main(){
        int choice,value;
        while(1){
                printf("\n---CIRCULAR QUEUE MENU---\n");
                printf("1.ENQUEUE(INSERT)\n");
                printf("2.DEQUEUE(DELETE)\n");
                printf("3.DISPLAY\n");
                printf("4.EXIT\n");
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
                                printf("INVALID CHOICE!\n");
                        }
        }
        return 0;
}
