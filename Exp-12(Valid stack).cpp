#include <stdio.h>
#define MAX_SIZE 10
struct Stack
{
    int data[MAX_SIZE];
    int top;
};
void initialize(struct Stack *s) 
{
    s->top = -1;
}
int isEmpty(struct Stack *s)
{
    return s->top == -1;
}
int isFull(struct Stack *s) 
{
    return s->top == MAX_SIZE - 1;
}
void push(struct Stack *s, int value) 
{
    if (isFull(s)) 
	{
        printf("Stack is full. Cannot push.\n");
        return;
    }
    s->data[++s->top] = value;
}
int pop(struct Stack *s) 
{
    if (isEmpty(s)) 
	{
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return s->data[s->top--];
}
int main() 
{
    struct Stack myStack;
    initialize(&myStack);
    push(&myStack, 10);
    push(&myStack, 20);
    push(&myStack, 30);
    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));
    printf("Popped element: %d\n", pop(&myStack));
    return 0;
}
