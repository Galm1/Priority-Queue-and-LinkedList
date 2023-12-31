#include <stdio.h>
#include <stdlib.h>

struct node //building a node struct with data and priority.
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
	new_node->data = data; //set the new_node data/priority and set its next to point to NULL, telling us it is last element.
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
	
	

	for (int i = 0, data, prio; i < x; i++){ //no longer using array so using &
		printf("\nEnter element %d: ", i + 1);
		scanf("%d", &data);
		printf("\nEnter priority of element %d (only 1 - 5): ", i + 1); //making sure the prio is only 1-5
		scanf("%d", &prio);
		
		if (prio < 1 || prio > 5){
			printf("Enter a priorty ONLY 1 - 5.\n");
			i--; //so user can reenter
			continue; // jump out and run loop again
		}
		
		enqueue(&pq, data, prio);
	}


    for (int i = 0; i < x - 1; i++) { //sort with prio
        struct node *current = pq.head;
        struct node *next_node = current->next;

        while (next_node != NULL) { //swap the data<->prio
            if (current->priority > next_node->priority) { //current takes head from above and compares to prio of next
                int temp_data = current->data; //set both current node to temp node to use for later
                int temp_priority = current->priority;
                current->data = next_node->data; //take next and set to current
                current->priority = next_node->priority;
                next_node->data = temp_data; //next node takes prio node daata and prio
                next_node->priority = temp_priority;
            }

            current = next_node;
            next_node = current->next;
        }
    }
	
	display(&pq);
	
	
	for (int i = 0; i < x; i++){
	char choice;
	
    printf("Dequeue an element (y for yes, n to exit)? "); // ask user for a dequeue then do so.
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y') {
        int dequeued = dequeue(&pq);
        if (dequeued != -1) {
            printf("Dequeued: Data = %d\n", dequeued);
        }
    } else return 0;
	
	printf("\nQueue after the Dequeue: \n");
	display(&pq);
	
	}


    while (pq.head != NULL) { //memory cleaning
        dequeue(&pq);
    }

    return 0;
	
	/*for (int i = 0; i < x; i++){
		printf("\n\nElement %d: %d", (i + 1), tempArr1[i]);
		printf("\n\nPriority of element %d: %d", (i + 1), tempArr2[i]);
	}
	
	printf("\nElement 'x+1' should be 9999, This is what it is: %d", tempArr2[x]);*/
	
}