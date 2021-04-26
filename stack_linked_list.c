#include <stdio.h>
#include <stdlib.h>

struct StackNode{
	int data; 
	struct StackNode* next; 
};

struct StackNode* createStackNode(int); 

int isEmpty(struct StackNode*);

void push(struct StackNode**, int); 

int peek(struct StackNode*); 

int main(){
	
	// Examples 
	struct StackNode* stack = NULL; 
	
	push(&stack, 10); 
	push(&stack, 5);
	push(&stack, 20); 
	push(&stack, 1000); 
	printf("\n%d is the last element\n", pop(&stack));
	printf("peek element is %d", peek(stack));
	return 0; 
}

struct StackNode* createStackNode(int data){
	struct StackNode* stack = (struct StackNode*) malloc(sizeof(struct StackNode));
	stack->data = data;
	stack->next = NULL; 
	
	return stack;
}

int isEmpty(struct StackNode* root){
	return !root;
}

void push(struct StackNode** root, int data){
	struct StackNode* stackNode = createStackNode(data);
	stackNode->next = *root; 
	*root = stackNode;
	
	printf("%d push to stack\n", data); 
}

int pop(struct StackNode** root){
	if(isEmpty(*root)){
		return INT_MIN;
	}
	
	struct StackNode* temp = *root; 
	
	*root = (*root)->next; 
	int popped = temp->data; 
	free(temp);
	
	return popped; 
}

int peek(struct StackNode* root){
	if(isEmpty(root)){
		return INT_MIN;
	}
	return root->data;
}
