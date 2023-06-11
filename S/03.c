#include <stdio.h>
#include <stdlib.h>
#define Max 3

typedef struct {
    int arr[Max];
    int top;
}Stack;

void push(Stack *sP);
void pop(Stack *sP);
void display(Stack *sP);

int main(){

    Stack *sP, s;
    sP = &s;

    sP->top = -1;

    printf("****Stack****\n");
    int c;
    do{
        printf("\n1. Push \n");
        printf("2. Pop \n");
        printf("3. Display \n");
        printf("0. Exit\n");
        printf("\nPlease enter your choice : ");
        scanf("%d",&c);

        switch(c){
        case 1:
            push(&s);
            break;

        case 2:
            pop(&s);
            break;

        case 3:
            display(&s);
            break;

        case 0:
            exit(1);
            break;

        default:
            printf("\nPlease enter valid number...\n");

        }
    }while(c != 0);
}

void push(Stack *sP){

    int item;

    if(sP->top == Max-1){
        printf("\n*******Stack is Full...\n");
    }
    else{
        printf("\nEnter you element : ");
        scanf("%d",&item);
        sP->top++;
        sP->arr[sP->top] = item;
        printf("%d is added to the Stack\n",item);
    }
}

void pop(Stack *sP){
    int item;

    if(sP->top == -1){
        printf("\n*******Stack is Empty...\n");
    }
    else{
        item = sP->arr[sP->top];
        sP->top--;
        printf("%d is pop\n",item);
    }
}

void display(Stack *sP){

    if(sP->top == -1){
        printf("\n*******Stack is Empty...\n");
    }
    else{
        int i;
        for(i=sP->top;i>=0;i--){
            printf(" %d\n",sP->arr[i]);
        }
    }
}


