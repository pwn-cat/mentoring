#include <stdio.h>

#define MAX_QUEUE_SIZE 100

int data[MAX_QUEUE_SIZE];//처음에 0번째 인덱스는 비워준다
int front;
int rear;

void init_queue(){	front=rear=-1;}
int is_empty(){return front==rear;}
int is_full(){return (rear+1)%MAX_QUEUE_SIZE==front;}
int size(){return (rear-front+MAX_QUEUE_SIZE)%MAX_QUEUE_SIZE;}

void enqueue(int x)
{
	rear=(rear+1)%MAX_QUEUE_SIZE;
	data[rear]=x;
}

int dequeue()
{
	front=(front+1)%MAX_QUEUE_SIZE;
	return data[front];
}

int main( )
{

	init_queue( );

	for(int i=1; i < 100; i++){
		enqueue( i );
		enqueue( i );
		printf("[%d]dequeue() --> %d\n", i, dequeue()); 
		printf("[%d]dequeue() --> %d\n", i, dequeue()); 
	}
	return 0;
}


