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


void enqueue(struct queue *q, int data){ 
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

void display(struct queue *q) {
    if (q->head == NULL) {
        printf("queue is empty\n");
        return;
    }

    printf("Order list: \n");
    struct node *x = q->head;
    while (x != NULL) {
        printf("%d", x->data);
        if (x->next != NULL) {
            printf(", "); // Print comma and space for all elements except the last one
        }
        x = x->next;
    }
    printf("\n");
}




int main() {
    struct queue q;
    q.head = NULL;
    q.tail = NULL;
    int order = 0;

    printf("Menu:  12 for Coffee | 22 for Taco | 30 for Ice Cream\n");

    do {
        printf("Enter order number (or 0 to exit): ");
        if (scanf("%d", &order) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }
        if (order == 0) {
            break;
        }
        enqueue(&q, order);
    } while (1);

    display(&q);
	
	while (q.head != NULL){
		dequeue(&q);
		display(&q);
	}
	printf("EXITING...");
    return 0;
}