#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initializeStack(struct Stack* stack);
int isEmpty(struct Stack* stack);
void peek(struct Stack* stack);
void pop(struct Stack* stack);
void push(struct Stack* stack);

int main() {

    struct Stack stack;
    initializeStack(&stack);

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
            push(&stack);
            break;

        case 2:
            pop(&stack);
            break;

        case 3:
            display(&stack);
            break;

        case 0:
            exit(1);
            break;

        default:
            printf("\nPlease enter valid number...\n");

        }
    }while(c != 0);


    return 0;
}

void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }

    struct Node* current = stack->top;
    printf("Stack: \n");
    while (current != NULL) {
        printf("%d \n", current->data);
        current = current->next;
    }
    printf("\n");
}

void peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    printf("Peek is %d\n",stack->top->data);
}

void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow!\n");
        return -1;
    }
    int data = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    printf("%d is POP\n",data);
}

void push(struct Stack* stack) {
    int data;
    printf("\nEnter you element : ");
    scanf("%d",&data);
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d is PUSH\n",data);
}


