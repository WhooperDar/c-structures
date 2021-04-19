#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data; 
	struct Node* next;
};

struct Node* createSinglyNode(int); 

struct Node* insertAtBeginning(struct Node*, int); 

void printCircularList(struct Node*);

int main(){
	
	int data = 4; 
	struct Node* tail = NULL; 
	
	tail = createSinglyNode(data);
	tail = insertAtBeginning(tail, 40);
	tail = insertAtBeginning(tail, 50);
	
	printCircularList(tail);
	
	return 0; 
}

struct Node* createSinglyNode(int data){
	struct Node* tail = malloc(sizeof(struct Node));
	tail->data = data;
	tail->next = tail;
	
	return tail; 
}

struct Node* insertAtBeginning(struct Node* tail, int data){
	struct Node* newNode = createSinglyNode(data);
	
	newNode->next = tail->next; 
	tail->next = newNode; 
	
	return tail;
}

void printCircularList(struct Node* tail) {
	struct Node* ptr = tail->next;
	
	do {
		printf("%d -> ", ptr->data);
		ptr = ptr->next; 
	} while(ptr != tail->next);
}
