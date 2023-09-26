#include <stdio.h>
#include <stdlib.h>
#define MAX 5  //is this nessasary? I dont know yet. We only want 5 user inputs, so maybe.

struct node //building a node struct.
{
	int data;
	struct node *next;
};

struct queue //building a struct for queue.
{
	struct node *head;
	struct node *tail;
};

void enqueue(struct queue *q, int data){ //enqueue takes a 'queue' struct pointer "q" and data.
	struct node *new_node = malloc(sizeof(struct node)); //allocate needed memory for node new_node.
	new_node->data = data; //set the new_node data and set its next to point to NULL, telling us it is last element.
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
	struct queue q;
	q.head = NULL;
	q.tail = NULL;
	enqueue(&q, 1);
	enqueue(&q, 2);
	enqueue(&q, 3);
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	printf("%d\n", dequeue(&q));
	return 0;
}
