#include <stdio.h>
#include <stdlib.h>

struct Node{
	struct Node* prev; 
	int data; 
	struct Node* next;
};

void printDoubly(struct Node*);

struct Node* createNode(struct Node*, int);
 
void insertAtEnd(struct Node*, int);

struct Node* insertAtBeginning(struct Node*, int); 

struct Node* deleteFirstNode(struct Node*);

struct Node* deleteLastNode(struct Node*);

struct Node* insertAfterPosition(struct Node*, int, int);

struct Node* insertBeforePosition(struct Node*, int, int); 

struct Node* reverseLinkedList(struct Node*);

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
	
	head = deleteFirstNode(head); 
	printDoubly(head);
	
	head = deleteLastNode(head); 
	printDoubly(head);
	
	head = insertAfterPosition(head, 40, 2); 
	printDoubly(head);
		
	head = insertBeforePosition(head, 50, 3); 
	printDoubly(head);
	
	head = reverseLinkedList(head);
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

struct Node* createNode(struct Node* node, int data){
	node = malloc(sizeof(struct Node*));
	node->prev = NULL;
	node->data = data; 
	node->next = NULL;
	
	return node;
}

void insertAtEnd(struct Node* head, int element){
	
	struct Node* ptr = head; 
	struct Node* newData = NULL; 
	
	newData = createNode(newData, element);
	
	while( ptr->next != NULL){
		ptr = ptr->next;
	}
	
	ptr->next = newData; 
	newData->prev = ptr; 
	newData->next = NULL;
}

struct Node* insertAtBeginning(struct Node* head, int element){
	
	struct Node* temp = NULL; 
	
	temp = createNode(temp, element);
	
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

struct Node* deleteFirstNode(struct Node* head){
	
	struct Node* ptr = head;
	ptr->prev = NULL;	
	head = ptr->next; 
	
	free(ptr);
	
	return head;
}

struct Node* deleteLastNode(struct Node* head){
	
	struct Node* ptr = head;
	if(head->next == NULL){
		head = NULL;
		free(head);
	}	
	
	while(ptr->next->next != NULL){
		ptr = ptr->next;
	}
	
	ptr->prev = NULL; 
	ptr->next = NULL; 
	free(ptr->next);
	
	return head;
}

struct Node* insertAfterPosition(struct Node* head, int elementData, int index){
	
	struct Node* temp = head; 
	struct Node* temp2 = NULL; 
	
	// New Node 
	struct Node* newNode = NULL; 
	newNode = createNode(newNode, elementData);
	
	// Traverse Linked List to locate index
	while (index != 1){
		temp = temp->next; 
		index--; 
	}	
		
	if (temp->next == NULL){ // If index reach last part 
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = NULL;
	} else {		
	
		temp2 = temp->next;
		temp->next = newNode;
		temp2->prev = newNode; 
		newNode->prev = temp; 
		newNode->next = temp2; 
	}
	return head;
}

struct Node* insertBeforePosition(struct Node* head, int elementData, int index){
	struct Node* ptr = head; 
	struct Node* ptr2 = NULL;
	
	struct Node* newNode = NULL; 
	newNode = createNode(newNode, elementData);
	
	while(index > 2){
		ptr = ptr->next; 
		index--;
	}	
	
	ptr2 = ptr->next;
	ptr->next = newNode; 
	ptr2->prev = newNode; 
	newNode->prev = ptr; 
	newNode->next = ptr2;  
		
	return head;
}

struct Node* reverseLinkedList(struct Node* head){
	struct Node* ptr = head; 
	struct Node* ptr2 = ptr->next;
	
	ptr->next = NULL; 
	ptr->prev = ptr2;
	 
	while( ptr2 != NULL ){	
		ptr2->prev = ptr2->next;
		ptr2->next = ptr; 
		ptr = ptr2; 
		ptr2 = ptr2->prev;
	}	
	
	head = ptr;
	
	return head;
}
