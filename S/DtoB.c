#include<stdio.h>
#include <stdlib.h>
#define Max 10

typedef struct {
    int arr[Max];
    int top;
}Stack;

int isFull(Stack *sPtr);
int isEmpty(Stack *sPtr);
void push(Stack *sPtr, int i);
int pop(Stack *sPtr);

void main(){

    Stack *sPtr,st;
    sPtr = &st;

    sPtr->top = -1;

    int num;

    printf("\nEnter decimal number:");
    scanf("%d",&num);

    while(num!=0){
        if(!isFull(&st)){
            push(&st,num%2);
            num = num/2;
        }
        else{
             printf("\nStack overflow");
             exit(0);
        }
    }

    printf("\n1");

    while(!isEmpty(&st)){
        num = pop(&st);
        printf("%d",num);
    }
}

int isFull(Stack *sPtr){
    if(sPtr->top==Max-1){
        return 1;
    }
    return 0;
}

int isEmpty(Stack *sPtr){
    if(sPtr->top==-1){
        return 1;
    }
    return 0;
}

void push(Stack *sPtr, int i){
    sPtr->top++;
    sPtr->arr[sPtr->top] = i;
}

int pop(Stack *sPtr){
    int item;
    item = sPtr->arr[sPtr->top];
    sPtr->top--;
    return item;
}
