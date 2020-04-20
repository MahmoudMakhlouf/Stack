// C program for array implementation of stack
#include <stdio.h>
#include <stdlib.h>

//boolean expression
typedef enum boolean
{
	false,true
}bool;

// A structure to represent a stack
typedef struct Stack {
	int top;
	unsigned capacity;
	int *data;
}STACK;

// function to create a stack of given capacity. It initializes size of
// stack as 0
STACK* createStack(unsigned capacity)
{
	STACK* stack = (STACK*)malloc(sizeof(STACK));
	stack->capacity = capacity;
	stack->top = -1;
	stack->data = (int*)malloc(stack->capacity * sizeof(int));
	return stack;
}

// Stack is full when top is equal to the last index
bool isFull(STACK* stack)
{
	if( stack->top == stack->capacity - 1)
		return true;
	else
		return false;
}

// Stack is empty when top is equal to -1
bool isEmpty(STACK* stack)
{
	if( stack->top == -1)
		return true;
	else
		return false;
}

// Function to add an item to stack. It increases top by 1
void push(STACK* stack, int item)
{
	if (isFull(stack))
	{
		printf("The stack is full, can't add element\n");
		return;
	}

	stack->data[++stack->top] = item;
	printf("%d pushed to stack\n", item);
}

// Function to remove an item from stack. It decreases top by 1
void pop(STACK* stack)
{
	if(isEmpty(stack))
	{
		printf("The stack is empty\n");
	}
	else
	{
		printf("%d popped from stack\n",stack->data[stack->top--]);
		stack->data[stack->top+1]=0;
	}
}

// Function to return the top from stack without removing it
int peek(STACK* stack)
{
	if (isEmpty(stack))
		printf("The stack is empty\n");
	return stack->data[stack->top];
}

// Driver program to test above functions
int main()
{
	///////////////////////////////
	STACK* stack = createStack(10);
	///////////////////////////////
	int i=0;
	while (i<(stack->capacity)+3)
	{
		push(stack,i+1);
		i++;
	}
	////////////////////////////////
	while(peek(stack)!=5)
	{
		pop(stack);
	}
	////////////////////////////////
	for(i=0;i<=stack->top;i++)
	{
		printf("%d\n",stack->data[i]);
	}
	////////////////////////////////
	return 0;
}
