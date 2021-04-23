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

struct Node* insertAtEndNode(struct Node*, int); 

struct Node* createCircularSingly(struct Node*);

void deleteFirstNode(struct Node*); 

void deleteLastNode(struct Node*); 

int main(){
	
	// Examples
	 
	struct Node* tail = NULL; 
	tail = createCircularSingly(tail);
	tail = insertAtBeginning(tail, 40);
	tail = insertAtBeginning(tail, 50);
	tail = insertAtBeginning(tail, 60);

	printCircularList(tail);

	tail = insertIntermediate(tail, 30, 1); 
	
	printCircularList(tail);
	
	tail = insertAtEndNode(tail, 10); 
	printCircularList(tail);

	deleteFirstNode(tail);
	printCircularList(tail);
	
	deleteLastNode(tail); 
	printCircularList(tail);
		
	return 0; 
}

// Node Creator
struct Node* createSinglyNode(int data){
	struct Node* tail = malloc(sizeof(struct Node));
	tail->data = data;
	tail->next = tail;
	
	return tail; 
}

// insert At Beginning 
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

// Print Whole Circular Linked List 
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

// Insert At the End
struct Node* insertAtEndNode(struct Node* tail, int data) {
	struct Node* newNode = createSinglyNode(data);
	
	if (tail == NULL){
		return newNode;
	}
	
	struct Node* ptr = tail->next; 
	
	do {
		
		ptr = ptr->next;	
		
	} while(ptr != tail->next); 
	
	newNode->next = tail->next; 
	tail->next = newNode; 
	tail = tail->next;
	
	return tail;
}

// Whole Circular Linked List 
struct Node* createCircularSingly(struct Node* tail){
	int i, data, no_of_nodes = 0; 
	
	printf("\nEnter the number of nodes: "); 
	scanf("%d", &no_of_nodes); 
	
	if(no_of_nodes == 0){
		return tail;
	}
	
	for(i = 0; i < no_of_nodes; i++){
		printf("Enter node %d: ", i+1);
		scanf("%d", &data); 
		tail = insertAtEndNode(tail, data); 
	}
	
	return tail;
}

void deleteFirstNode(struct Node* tail){ 
	struct Node* tptr = tail->next;
	
	tail->next = tptr->next;  
	free(tptr); 
	tptr = NULL; 
}

void deleteLastNode(struct Node* tail){
	struct Node* head = tail->next;
	
	while(head->next != tail){
		head = head->next;
	}
 
	head->next = tail->next;
	tail = head;
	head = head->next; 
	head = NULL; 
	free(head);
}
