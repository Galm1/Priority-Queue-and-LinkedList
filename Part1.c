#include <stdio.h>
#include <stdlib.h>

struct node //building a node struct.
{
	int data;
	int priority;
	struct node *next;
};

struct queue //building a struct for queue.
{
	struct node *head;
	struct node *tail;
};

void enqueue(struct queue *q, int data, int priority){ //enqueue takes a 'queue' struct pointer "q" and data.
	struct node *new_node = malloc(sizeof(struct node)); //allocate needed memory for node new_node.
	new_node->data = data; //set the new_node data and set its next to point to NULL, telling us it is last element.
	new_node->priority = priority;
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

void display(struct queue *q){
	if (q->head == NULL) {
		printf("queue is empty\n");
		return;
	}
	
	printf("Priority Queue: \n");
	struct node *x = q->head;
	while (x != NULL){
		printf("(%d , %d)\n", x->data, x->priority);
		x = x->next;
	}
}



int main()
{
	int x = 0;
	struct queue pq;
	pq.head = NULL;
	pq.tail = NULL;
	
	printf("Enter the length of the queue: ");
	scanf("%d", &x);
	
	
	/*for (int i = 0; i < x; i++){
		printf("\nEnter element %d: ", i + 1);
		scanf("%d", &(tempArr1[i]));
		printf("\nEnter priority of element %d (only 1 - 5): ", i + 1);
		scanf("%d", &(tempArr2[i]));
	}

	
	
	for (int i = 0; i < x; i++){
		printf("\n\nElement %d: %d", (i + 1), tempArr1[i]);
		printf("\n\nPriority of element %d: %d", (i + 1), tempArr2[i]);
	}
	
	printf("\nElement 'x+1' should be 9999, This is what it is: %d", tempArr2[x]);*/
	
}