//new header
#include <stdio.h>
#include <stdlib.h>

node* front = NULL;
node* rear = NULL;


typedef struct node{
	int data;
	struct node* next;
}node;

static void enQ(int data){
	node* temp = (node*)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	
	if(front == NULL && rear == NULL)//list is empty
	{
		front = rear = temp;
	}
	rear->next = temp;
	rear = temp;
}

static void DeQQ(){
	node* temp = front;
	if(front == NULL) {
		printf("empty queue\n");
		return;}
	if(front == rear) {
		front = rear = NULL;}
	else{
		front = front->next;}
	free(temp);
}

static int frontVal(){
	node* temp = (node*)malloc(sizeof(struct node));
	temp = front;
	int value = temp->data;
	return value;
}