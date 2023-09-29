#include <stdio.h>
#include <stdlib.h>


struct node
{
	int data;
	struct node* next;
};

struct queue 
{
	struct node *head;
	struct node *tail;
};


void enqueue(struct queue *q, int data, int priority){ 
	struct node *new_node = malloc(sizeof(struct node)); 
	new_node->data = data; 
	new_node->next = NULL;
	
	if (q->tail == NULL){
		q->head = new_node;
		q->tail = new_node;
		return;
	} else {
		q->tail->next = new_node;
		q->tail = new_node;
	}
}

int dequeue(struct queue *q){
	if (q->head == NULL){
		printf("Queue is empty");
		return -1; 
	}
	int data = q->head->data;
	struct node *temp = q->head;
	q->head = q->head->next;
	if(q->head == NULL){
		q->tail = NULL;
	}
	free(temp);
	return data;
}

void display(struct queue *q){
	if (q->head == NULL) {
		printf("queue is empty\n");
		return;
	}
	
	printf("Priority Queue: \n");
	struct node *x = q->head;
	while (x != NULL){
		printf("(%d ,\n", x->data);
		x = x->next;
	}
}




int main()
{
	printf("Hello World!");
}