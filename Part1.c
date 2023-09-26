#include <stdio.h>
#include <stdlib.h>
#define MAX 5

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
}





int main()
{
	
}
