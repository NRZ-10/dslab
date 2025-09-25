#include <stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *link;
};
struct node *head=NULL;

void insert_front(int x);
void insert_end(int x);
void delete_any(int key);
void display();
void search_node(int key);

int main(){
	int ch,x,key;
	do{
	    printf("Enter the option\n 1.INSERT FRONT \n 2.INSERT END \n 3.DELETE \n 4.DISPLAY \n 5.SEARCH \n 6.EXIT \n");
	    scanf("%d",&ch);
	    switch(ch){
		    case 1:
			    printf("Enter the new data: ");
			    scanf("%d",&x);
			    insert_front(x);
			    break;
		    case 2:
			    printf("Enter the new data: ");
			    scanf("%d",&x);
			    insert_end(x);
			    break;
		    case 3:
			    printf("Enter the node to be deleted: ");
			    scanf("%d",&key);
			    delete_any(key);
			    break;
		    case 4:
			    display();
			    break;
		    case 5:
			    printf("Enter the data to search: ");
			    scanf("%d",&key);
			    search_node(key);
			    break;
		    case 6:
			    break;
		    default:
			    printf("Enter a valid choice \n");
		}
	}while( ch!= 6);

	return 0;
}
void display(){
	struct node *ptr;
	if(head == NULL)
		printf("\n Linked list is empty \n");
	else{
		ptr=head;
		printf("\n List elements are: ");
		while(ptr != NULL){
			printf("%d\t",ptr->data);
			ptr=ptr->link;
		}
		printf("\n");
	}
}
void insert_front(int x){
	struct node *new_node;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=x;
	new_node->link=head;
	head=new_node;
	display();
}
void insert_end(int x){
	struct node *new_node,*ptr;
	new_node=(struct node*)malloc(sizeof(struct node));
	new_node->data=x;
	new_node->link=NULL;
	if(head == NULL)
		head=new_node;
	else{
		ptr=head;
	while(ptr->link != NULL){
		ptr=ptr->link;
	}
	ptr->link=new_node;
        }
	display();
}
void delete_any(int key){
	struct node *prev,*curr,*temp;
	if(head == NULL){
		printf("Deletion not possible\n");
	}
	else if(head->data == key){
		temp=head;
		head=head->link;
		free(temp);
	}
	else{
		prev=head;
		curr=head;
		while( curr!= NULL && curr->data != key){
			prev=curr;
			curr=curr->link;
		}
		if(curr == NULL){
			printf("Data not found\n");
		}
		else{
			prev->link=curr->link;
			free(curr);
		}
	}
	display();
}
void search_node(int key){
	struct node *ptr=head;
	int pos=0;
	while(ptr != NULL){
		if(ptr->data == key){
			printf("Data found at position %d \n", pos);
			return;
		}
		ptr=ptr->link;
		pos++;
	}
	printf("Data not found in the list \n");
}


