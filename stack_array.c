#include <stdio.h>
#include <stdlib.h>

struct Stack {
	int top; 
	unsigned capacity; 
	int* array; 
};

struct Stack* createStack(unsigned);

int isFull(struct Stack*);

void push(struct Stack*, int);

int pop(struct Stack*); 

int peek(struct Stack*); 

int main(){
	
	struct Stack* stack = createStack(100); 
	
	push(stack, 5); 
	push(stack, 10); 
	push(stack, 20); 
	
	printf("pop = %d\n", pop(stack)); 
	printf("peek = %d\n", peek(stack)); 
	
	return 0; 
}

struct Stack* createStack(unsigned capacity){
	struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
	stack->top = -1; 
	stack->capacity = capacity; 
	stack->array = (int*)malloc(sizeof(int));
	
	return stack;
}

int isFull(struct Stack* stack){
	return stack->top == stack->capacity - 1; 
}

int isEmpty(struct Stack* stack){
	return stack->top == -1; 
}

void push(struct Stack* stack, int data){
	if (isFull(stack)){
		return; 
	}
	
	stack->array[++stack->top] = data; 
	printf("%d push to stack\n", data);
}

int pop(struct Stack* stack){
	if(isEmpty(stack)){
		return INT_MIN; 
	}
	else {
		return stack->array[stack->top--];	
	}
}

int peek(struct Stack* stack){
	if(isEmpty(stack)){
		return INT_MIN; 
	} else { return stack->array[stack->top];}
}



