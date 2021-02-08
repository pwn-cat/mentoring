#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 1000
#define FALSE 0
#define TRUE 1

typedef struct _stack
{
	char data[1000];
	int top;
}Stack;

Stack stack;
void init(){
	stack.top=0;
}

int isFull()
{
	if(stack.top==MAX_SIZE)	return TRUE;
	else					return FALSE;
}

int isEmpty()
{
	if(stack.top==0)	return TRUE;
	else				return FALSE;
}

char pop()
{
	if(!isEmpty())	return	stack.data[--stack.top];
	else
	{
		printf("괄호수가 맞지 않습니다\n");
		exit(-1);
	}
}

char peek()
{
	if(!isEmpty())	return stack.data[stack.top-1];
	else			return -1;
}

void push(char x)
{
	if(isFull())	return;
	else		stack.data[stack.top++] = x;
}


int main()
{
	char input[1000];
	fgets(input, 1000, stdin);
	for(int i=0;i<strlen(input);i++)
	{
		//여는 괄호일때 스택에 넣음
		if(input[i]=='('||input[i]=='{'||input[i]=='[')
		{
			push(input[i]);continue;
		}
		if((input[i]==')'||input[i]=='}'||input[i]==']')==0)
			continue;
		//닫는 괄호일때 검사
		char tmp=pop();
		switch(input[i])
		{
			case ')':
				if(tmp!='(')
				{printf(" 괄호 수 안맞음");return 0;}
				break;
			case '}':
				if(tmp!='{')
				{printf(" 괄호 수 안맞음");return 0;}
				break;
			case ']':
				if(tmp!='[')
				{printf(" 괄호 수 안맞음");return 0;}
				break;
			default:
				break;
		}
	}
	if(stack.top!=0)
	{
		printf("괄호수가 맞지 않습니다\n");
		return 0;
	}


	printf("괄호수가 맞습니다.\n");
	return 0;
	
}
