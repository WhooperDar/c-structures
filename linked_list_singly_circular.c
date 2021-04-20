#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data; 
	struct Node* next;
};

struct Node* createSinglyNode(int); 

struct Node* insertAtBeginning(struct Node*, int); 

void printCircularList(struct Node*);

struct Node* insertIntermediate(struct Node*, int, int);

int main(){
	 
	struct Node* tail = NULL; 
	
	tail = insertAtBeginning(tail, 40);
	tail = insertAtBeginning(tail, 50);
	tail = insertAtBeginning(tail, 60);

	printCircularList(tail);

	tail = insertIntermediate(tail, 30, 1); 
	
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
	
	if(tail == NULL){
		newNode = createSinglyNode(data); 
		return newNode; 
	}
	
	newNode->next = tail->next; 
	tail->next = newNode; 
	
	return tail;
}

void printCircularList(struct Node* tail) {
	printf("\n");
	
	struct Node* ptr = tail->next;
	
	do {
		printf("%d -> ", ptr->data);
		ptr = ptr->next; 
	} while(ptr != tail->next);
}

// Insert middle node 
struct Node* insertIntermediate(struct Node* tail, int data, int index){
	
	
	struct Node* ptr = tail->next;
	struct Node* newNode = createSinglyNode(data);
	
	while(index > 1){
		ptr = ptr->next;
		index--;
	}
	
	newNode->next = ptr->next;
	ptr->next = newNode;
	
	if(ptr == tail){
		tail = tail->next;
	}
	
	return tail;
}
