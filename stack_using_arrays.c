#include<stdio.h>
#include<stdlib.h>
#define MAX 5
typedef struct{
    int top;
    int data[MAX];
}stack;

//function to push a element in stack
void push(stack *s, int v){
    if(s->top>=MAX){
        printf("stack overflow\n");
    }
    s->top++;
    s->data[s->top]=v;
}

//function to pop the top element out of stack
int pop(stack *s){
    if(s->top==-1){
        printf("stack Underflow\n");
        return 0;
    }
    int a=s->data[s->top];
    s->top=s->top-1;
    return a;
}

//function to check the element at the top of stack
int peek(stack s){
    if(s.top==-1)
    {
        printf("Empty stack......Underflow condition\n");
        return 0;
    }
    int a=s.data[s.top];
    return a;
}

//function to check if the stack is Empty
int isEmpty(stack s){
    if(s.top==-1){
        return 1;
    }
    else{
        return 0;
    }
}

//function to display the contents of the array
void display(stack s){
    while(s.top>-1){
        printf("%d \n", s.data[s.top]);
        s.top--;
    }
}

int main(){
    stack s1;
    s1.top=-1;
    push(&s1, 5);
    push(&s1, 7);
    push(&s1, 3);
    push(&s1, 1);
    
    // int a=peek(s1);
    // printf("peeked data is: %d \n", a);
    int check=isEmpty(s1);
    printf("%d\n", check);
    display(s1);

    return 0;
}