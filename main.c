#include <stdio.h>
#include <stdlib.h>

#define MAXSTACK 5

typedef struct stack{
    int data[MAXSTACK];
    int top;
}stack;

typedef enum {true,false} boolean;

void create_stack(stack *s){
    s->top=-1;
}

boolean is_stack_full(stack *s){
    return (s->top==MAXSTACK-1);
}

boolean is_stack_empty(stack *s){
    return (s->top==-1);
}

void push(stack *s, int element){
    if(is_stack_full(s)){
        printf("stack already full\n");
    }else{
        s->data[++s->top]=element;
    }
}

void pop(stack *s){
    if(is_stack_empty(s)){
        printf("stack already empty\n");
    }else{
        int element=s->data[s->top--];
        free(element);
    }
}

void display(stack *s){
    int i;
    for (i=0;i<=s->top;i++){
        printf("%d \t",s->data[i]);
    }
    printf("\n");
}

int main()
{
    stack s;
    create_stack(&s);
    push(&s,10);
    push(&s,20);
    push(&s,30);
    display(&s);
    pop(&s);
    display(&s);
    return 0;
}
