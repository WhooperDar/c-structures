#include <stdio.h>
#include <stdlib.h>

struct QNode{
	int data; 
	struct QNode* next; 
};

struct Queue{
	struct QNode *front, *rear; 
};

void enqueue(struct Queue*, int);

struct QNode* dequeue(struct Queue*);

struct QNode* createNode(int);

struct Queue* createQueue(); 
 
int main(){
	
	// Examples
	
	struct Queue* q = createQueue();
	
	enqueue(q, 10); 
	enqueue(q, 30); 
	enqueue(q, 150); 
	enqueue(q, 13); 
	
	printf("%d rear\n", q->rear->data);
	printf("%d front\n", q->front->data);
	
	return 0; 
}
struct Queue* createQueue(){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue)); 
	q->front = q->rear = NULL; 
	
	return q; 
} 

void enqueue(struct Queue* q, int data){
	struct QNode* temp = createNode(data); 
	
	if(q->rear == NULL){
		q->front = q->rear = temp;
		printf("%d added to queue\n", data); 
		return; 
	}
	
	q->rear->next = temp; 
	q->rear = temp; 
	
	printf("%d added to queue\n", data);
}

struct QNode* dequeue(struct Queue* q){
	if(q->front == NULL){
		return NULL; 
	}	
	
	struct QNode* temp = q->front; 
	q->front = q->front->next; 
	
	
	if(q->front == NULL){
		q->rear = NULL;
	}
	
	return temp;
}

struct QNode* createNode(int data){
	struct QNode* Node = (struct QNode*)malloc(sizeof(struct QNode)); 
	Node->data = data; 
	Node->next = NULL;
	
	return Node;
}
