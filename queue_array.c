#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Array implementation of Queue
struct Queue{
	unsigned capacity; 
	int front, rear, size; 
	int* array; 
};

struct Queue* createQueue(unsigned); 

int isFull(struct Queue*);

int isEmpty(struct Queue*);

void enqueue(struct Queue*, int); 

int dequeue(struct Queue*); 

void printQueue(struct Queue*); 

int front(struct Queue*); 

int rear(struct Queue*); 

int main(){
	
	struct Queue* queue = createQueue(100); 
	
	enqueue(queue, 9); 
	enqueue(queue, 10); 
	
	enqueue(queue, 50); 
	enqueue(queue, 20); 
	
	printQueue(queue); 
	
	printf("\n%d is dequeue\n",dequeue(queue)); 
	
	printf("rear = %d\n", rear(queue));
	
	printf("front = %d\n", front(queue));
	
	return 0; 
}

struct Queue* createQueue(unsigned capacity){
	struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue)); 
	queue->capacity = capacity; 
	queue->front = queue->size = 0; 
	queue->rear = capacity - 1; 
	queue->array = (int*)malloc(queue->capacity * sizeof(int));
	
	return queue;
}

int isFull(struct Queue* queue){
	return queue->size == queue->capacity; 
}

int isEmpty(struct Queue* queue){
	return (queue->size == 0);
}

void enqueue(struct Queue* queue, int data){
	if(isFull(queue)){
		printf("Overflow Condition!\n"); 
		return; 
	}
	
	// index rear
	queue->rear = (queue->rear + 1) % queue->capacity; 
	queue->size = queue->size + 1; 
	queue->array[queue->rear] = data;
	
	printf("\n%d added to queue\n", data);
}

int dequeue(struct Queue* queue){
	if(isEmpty(queue)){
		return INT_MIN; 
	}
	
	int data = queue->array[queue->front]; 
	queue->front = (queue->front + 1) % queue->capacity; 
	queue->size -= 1; 
	
	return data; 
}

void printQueue(struct Queue* queue){ 
	int i; 
	
	printf("\n"); 
	
	for(i = 0; i < queue->size; i++){
		printf("%d ", queue->array[i]); 
	}
}

int front(struct Queue* queue){
	int front = queue->front;
	return queue->array[front]; 
}


int rear(struct Queue* queue){
	int rear = queue->rear; 
	return queue->array[rear]; 
}
