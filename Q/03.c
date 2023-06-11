#include<stdio.h>
#include<stdlib.h>
#define MAX 5

int queue[MAX];
int rear = -1;
int front = -1;
int element,c;

int isFull();
int isEmpty();
void enqueue(int element);
int dequeue();
void display();
int peek();

void main(){

    do{
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Peek\n0. Exit");
        printf("\n\nEnter your choise : ");
        scanf("%d",&c);

        switch(c)
        {
        case 0:
            printf("Exiting...\n");
            exit(0);
            break;

        case 1:
            printf("\nEnter Element to be Inserted : ");
            scanf("%d",&element);
            enqueue(element);
            break;

        case 2:
            element = dequeue();
            printf("\nDeleted Element From Queue : %d\n", element);
            break;

        case 3:
            display();
            break;

        case 4:
            printf("\nElement at Front of Queue : %d\n", peek());
            break;

        }

    }while(1);

}

int isFull(){
    if(rear == MAX-1){
        return 1;
    }
    return 0;
}


int isEmpty(){
    if(front == -1 || front == rear + 1){
        return 1;
    }
    return 0;
}


void enqueue(int element){
    if(isFull()){
        printf("\nQueue is Overflow...\n");
    }
    else if(front == -1){
        front = 0;
    }
    if(!isFull()){
        rear++;
        queue[rear] = element;
        printf("Element inserted\n");
    }
}

int dequeue(){
    if(isEmpty()){
        printf("\nQueue is Underflow...\n");
    }
    else{
        int i = queue[front];
        front++;
        return i;
    }
}

void display(){
    if(!isEmpty){
        printf("\nQueue is Underflow...\n");
    }
    else{
        printf("\nQueue : ");
        int i;
        for(i=front;i<=rear;i++){
            printf("%d ",queue[i]);
        }
        printf("\n");
    }

}


int peek(){
    if(isEmpty()){
        printf("\nQueue is Underflow...\n");
    }
    else{
        int i = queue[front];
        return i;
    }
}
