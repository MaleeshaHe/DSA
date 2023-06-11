#include <stdio.h>
#include <stdlib.h>
#define Max 3

struct stack{
    int arr[Max];
    int top;
}stack;

void push();
void pop();
void display();

int main(){

    stack.top = -1;

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
            push();
            break;

        case 2:
            pop();
            break;

        case 3:
            display();
            break;

        case 0:
            exit(1);
            break;

        default:
            printf("\nPlease enter valid number...\n");

        }
    }while(c != 0);
}

void push(){
    int item;

    if(stack.top == Max-1){
        printf("\n*******Stack is Full...\n");
    }
    else{
        printf("\nEnter you element : ");
        scanf("%d",&item);
        stack.top++;
        stack.arr[stack.top] = item;
        printf("%d is added to the Stack\n",item);
    }
}

void pop(){
    int item;

    if(stack.top == -1){
        printf("\n*******Stack is Empty...\n");
    }
    else{
        item = stack.arr[stack.top];
        stack.top--;
        printf("%d is pop\n",item);
    }
}

void display(){

    if(stack.top == -1){
        printf("\n*******Stack is Empty...\n");
    }
    else{
        int i;
        for(i=stack.top;i>=0;i--){
            printf(" %d\n",stack.arr[i]);
        }
    }
}





























