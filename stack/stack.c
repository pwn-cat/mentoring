#include <stdio.h>

#define MAX_SIZE 1000
#define TRUE 1
#define FALSE 0

typedef struct _Stack{
	int data[1000];
	int top;
}Stack;

Stack stack;

void init()
{
	stack.top=0;
}

int isEmpty()
{
	if(stack.top!=0)	return FALSE;
	else				return TRUE;
}

int isFull()
{
	if(stack.top!=MAX_SIZE)	return FALSE;
	else					return TRUE;
}


int size()
{
	return stack.top;
}

int pop(){
	if(isEmpty())	return FALSE;
	return stack.data[--stack.top];
}

int push(int x)
{
	if(isFull())	return FALSE;

	stack.data[stack.top++]=x;
	return TRUE;
}

int peek()
{
	if(isEmpty())	return -1;
	return stack.data[stack.top-1];
}

int main()
{
	for(int i=1;i<=10;i++)
		push(i);

	printf("peek: %d \n",peek());
	
	for(int i=0;i<10;i++)
		printf("poped : %d\n",pop());
}

