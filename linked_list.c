#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data; 
	struct Node* next; 
} Node;

int countNodes(struct Node*);
 
void printLinkList(struct Node*); 

void insertAtEnd(int, struct Node*); 

struct Node* insertAtBeginning(int, struct Node*); 

struct Node* deleteFirstNode(struct Node*);

void deleteEndNode(struct Node* );

void deleteLastNode (struct Node*); 

struct Node* deletePosition(struct Node*, int);

struct Node* reverseLinkedList(struct Node*);

int main(){
	
	struct Node* head = NULL;
	head = (struct Node*)malloc(sizeof(struct Node)); 
	head->data = 10; 
	head->next = NULL; 
	
	struct Node* current = (struct Node*)malloc(sizeof(struct Node)); 
	current->data = 25; 
	current->next = NULL; 
	head->next = current; 
	
	current = (struct Node*)malloc(sizeof(struct Node));
	current->data = 60; 
	current->next = NULL; 
	
	head->next->next = current; 
	
	printLinkList(head);
	
	insertAtEnd(3, head); // Insert At End 
	printLinkList(head);
	
	head = insertAtBeginning(89, head);  // Insert At Beginning 
	printLinkList(head);

	
	head = deleteFirstNode(head); // Delete At First
	printLinkList(head);
	
	deleteEndNode(head);
	printLinkList(head);
	
	deleteLastNode(head);
	printLinkList(head);
	
	head = deletePosition(head, 2);
	printLinkList(head);
	
	insertAtEnd(3, head);
	insertAtEnd(8, head);
	insertAtEnd(10, head);
	insertAtEnd(11, head);
	printLinkList(head);

	head = reverseLinkedList(head); 
	printLinkList(head);	
	return 0;
}

int countNodes(struct Node* head){
	int count = 0; 
	
	if (head == NULL){
		printf("Linked List is empty!");  
	}
	
	struct Node *traverse = NULL; 
	traverse = head;  
	
	while(traverse != NULL){
		count++; 
		traverse = traverse->next; 
	}	
	
	return count;
}

void printLinkList(struct Node* head){
	
	printf("\n");
	if(head == NULL)
		printf("Linked List is Empty"); 
		
	struct Node* ptr = head; 
	
	while(ptr != NULL){
		
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
}

void insertAtEnd(int element, struct Node* head){
	
	struct Node* newNode = (struct Node*) malloc(sizeof(struct Node*));
	newNode->data = element; 
	newNode->next = NULL;
	
	struct Node* ptr = head; 
	while(ptr->next != NULL){
		ptr = ptr->next; 
	}
	
	ptr->next = newNode;
}

struct Node* insertAtBeginning(int element, struct Node* head){
	
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node)); 
	temp->data = element;
	temp->next = NULL; 

	if(head == NULL){
		head->data = element;
	}
	
	temp->next = head;
	head = temp;
	
	return head;
}

struct Node* deleteFirstNode(struct Node* head){
	
	if (head == NULL){
		printf("\nLinked List is already empty");
	} else {
		struct Node* temp = head; 
	
		head = temp->next;
		
		free(temp);
	}
	return head;
}

void deleteEndNode(struct Node* head){ // First Method (two pointers)
	
	struct Node* ptr1 = head; // Connection to last node
	struct Node* ptr2 = head; // Connection to second last node
	
	while(ptr1->next != NULL){
		ptr2 = ptr1; 
		ptr1 = ptr1->next;
	}
	
	ptr2->next = NULL;
	free(ptr1);
}

void deleteLastNode(struct Node* head){ // Second Method (single pointer)
	
	if(head == NULL){
		printf("\nLinked List is empty!"); 
	}
	else if(head->next == NULL){
		free(head); 
		head = NULL;
	}
	else {
		while(head->next->next != NULL){
			head = head->next;
		}
		free(head->next); 
		head->next = NULL;
	}
}

struct Node* deletePosition(struct Node* head, int index){
	
	struct Node* previous = head; 
	struct Node* current = head;
	
	if(index == 1){
		head = deleteFirstNode(head); 
		return head;
		
	} else {
		while(index != 1){
			previous = current;
			current = current->next;
			index--;
			
		}	
		previous->next = current->next;
		free(current);
		current = NULL;
	}
	
	return head;
}

struct Node* reverseLinkedList(struct Node* head){
	
	struct Node* prev = NULL; 
	struct Node* next = NULL;
	
	while(head != NULL){
		
		next = head->next;
		head->next = prev;
		prev = head;
		head = next;
	} 
	
	head = prev;
	
	return head;
}
