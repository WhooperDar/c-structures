#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node* prev; 
	int data; 
	struct Node* next;
};

void printDoubly(struct Node*);

void insertAtEnd(struct Node*, int);

struct Node* insertAtBeginning(struct Node*, int); 

int main(){
	
	struct Node* head = malloc(sizeof(struct Node));
	head->prev = NULL; 
	head->data = 18;
	head->next = NULL;
	
	struct Node* current = malloc(sizeof(struct Node));
	current->prev = head; 
	current->data = 20; 
	current->next = NULL;
	
	head->next = current;
	printDoubly(head);
	
	insertAtEnd(head, 99);
	printDoubly(head);
	
	head = insertAtBeginning(head, 125);
	printDoubly(head);
	return 0; 
}

void printDoubly(struct Node * head){
	
	printf("\n");
	if(head == NULL){ 
		printf("Doubly Linked List is empty!\n");
	}
	struct Node* ptr = head; 
	
	while( ptr != NULL){
		printf(" <- %d -> ", ptr->data);
		
		ptr = ptr->next;
	}
}

void insertAtEnd(struct Node* head, int element){
	
	struct Node* ptr = head; 
	struct Node* newData = malloc(sizeof(struct Node));
	newData->prev = NULL;
	newData->data = element;
	newData->next = NULL;
	
	while( ptr->next != NULL){
		ptr = ptr->next;
	}
	
	ptr->next = newData; 
	newData->prev = ptr; 
	newData->next = NULL;
}

struct Node* insertAtBeginning(struct Node* head, int element){
	
	struct Node* temp = malloc(sizeof(struct Node));
	temp->prev = NULL;
	temp->data = element; 
	temp->next = NULL;
	
	struct Node* ptr = head;
	
	
	if(head == NULL){
		head->prev = NULL; 
		head->data = element; 
		head->next = NULL;
	}
	
	temp->prev = NULL;
	temp->next = head; 
	head = temp;
	
	return head;
}


