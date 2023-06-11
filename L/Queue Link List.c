#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

void initializeQueue(struct Queue* queue);
int isEmpty(struct Queue* queue);
void enqueue(struct Queue* queue, int data);
void dequeue(struct Queue* queue);
void peek(struct Queue* queue);

int main() {
    struct Queue queue;
    initializeQueue(&queue);

    int option,element;

    while(1)
     {
         printf("\n1. Enqueue");
         printf("\n2. Dequeue");
         printf("\n3. Display All the Elements");
         printf("\n4. Front position");
         printf("\n5. Exit");
         printf("\n\nEnter your option:\t");


         scanf("%d", &option);
         switch(option)
         {
            case 1:
                printf("\nEnter Element to be Inserted:\t");
                scanf("%d", &element);
                enqueue(&queue,element);
                break;

         case 2:
                dequeue(&queue);
                break;

         case 3:
                display(&queue);
                break;

         case 4:
                peek(&queue);
                break;

         case 5:
                exit(1);
         }
    }
    printf("\n");

    return 0;
}

void initializeQueue(struct Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isEmpty(struct Queue* queue) {
    return (queue->front == NULL && queue->rear == NULL);
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
    printf("%d is enqueue\n",data);
}

void dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1;
    }

    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    free(temp);
    printf("%d is dequeue\n",data);
}

void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }

    struct Node* current = queue->front;
    printf("Queue: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}


void peek(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow!\n");
        return -1;
    }
    printf("Peek is %d\n",queue->front->data);
}
