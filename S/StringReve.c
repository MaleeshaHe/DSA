#include<stdio.h>
#include<stdlib.h>
# define Max 100

struct stack
{
    char arr[Max];
    int top;
}st;

void push(char str);
char pop();

void main(){

    char string[Max];

    int choice,i;
    st.top= -1;

    printf("\n\n enter your String :- ");
    scanf("%[^\n]s", string);

    for(i=0;i<strlen(string);i++){
        push(string[i]);
    }

    for(i=0;i<strlen(string);i++){
        string[i] = pop();
    }

    printf("\nReversed String is: %s\n",string);


}


void push(char str){

    if(st.top==Max-1){
        printf("\n\n\t the stack is full/overflow....");
    }
    else{
        st.top++;
        st.arr[st.top] = str;
    }
}

char pop(){

    char item;
    if(st.top==-1){
        printf("\n\n\t Stack is Empty/Underflow ......");
    }
    else{
        item = st.arr[st.top];
        st.top--;
    }
    return item;
}

