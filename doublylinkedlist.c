#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* prev;
	struct node* next;
};
struct node* head= NULL;

void insert_front(int x){
	struct node* newNode= (struct node*)malloc(sizeof(struct node));
	newNode->data=x;
	newNode->prev= NULL;
	newNode->next= head;

	if( head != NULL )
		head->prev=newNode;
	head=newNode;
	printf("%d inserted at front\n", x);
}

void insert_end(int x){
        struct node* newNode= (struct node*)malloc(sizeof(struct node));
        newNode->data=x;
	newNode->next= NULL;

	if( head==NULL ){
		newNode->prev=NULL;
		head=newNode;
	}
	else{
		struct node* temp=head;
		while(temp->next != NULL)
			temp=temp->next;
		temp->next=newNode;
		newNode->prev=temp;
	}
	printf("%d inserted at end\n", x);
}

void delete_any(int key){
	struct node* temp=head;
	while(temp != NULL && temp->data != key)
		temp=temp->next;
	if(temp == NULL){
		printf("%d not found in list\n", key);
		return;
	}
	if(temp->prev != NULL)
		temp->prev->next=temp->next;
	else
		head=temp->next;
	if(temp->next != NULL)
		temp->next->prev=temp->prev;
	free(temp);
	printf("%d deleted from list\n", key);
}

void search_node(int key){
	struct node* temp=head;
	int pos=1;
	while(temp != NULL){
		if(temp->data == key){
		printf("%d found at position %d\n", key,pos);
	        return;
		}
		temp=temp->next;
		pos++;
	}
	printf("%d not found in list\n", key);
}

void display(){
	struct node* temp=head;
	if( head == NULL ){
		printf("List is Empty\n");
		return;
	}
	printf("Doubly Linked list: ");
	while(temp != NULL){
		printf("%d <->",temp->data);
		temp=temp->next;
	}
	printf("NULL\n");
}

int main(){
	int ch,x,key;
	do{
		printf("\n----Doubly Linked List Operations----\n");
		printf("1.Insert at front\n");
		printf("2.Insert at end\n");
		printf("3.Delete node\n");
		printf("4.Search node\n");
		printf("5.Display list\n");
		printf("6.Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);

		switch(ch){
			case 1:
				printf("Enter value: ");
				scanf("%d",&x);
				insert_front(x);
				break;
			case 2:
                                printf("Enter value: ");
                                scanf("%d",&x);
                                insert_end(x);
                                break;
			case 3:
				printf("Enter value to delete: ");
				scanf("%d",&key);
				delete_any(key);
				break;
			case 4:
				printf("Enter value to search: ");
				scanf("%d",&key);
				search_node(key);
				break;
			case 5:
				display();
				break;
			case 6:
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid choice \n");
			}
	}while( ch != 6);
	return 0;
}







        	



