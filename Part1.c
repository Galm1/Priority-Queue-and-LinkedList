#include <stdio.h>
#include <stdlib.h>
#define MAX 5  //is this nessasary? I dont know yet. We only want 5 user inputs, so maybe.

struct node 
{
	int data;
	struct node *next;
};

struct queue
{
	struct node *head;
	struct node *tail;
};

void enqueue(struct queue *q, int data){
	struct node *new_node = malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	
	if (q->tail == NULL){
		q->head = new_node;
		q->tail = new_node;
	} else {
		q->head->next = new_node;
		q->tail = new_node;
	}
}

int dequeue(struct queue *q){
	if (q->head == NULL){
		return -1; //telling us queue is empty
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





int main()
{
	
}
