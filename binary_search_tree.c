#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode* nodeptr; 

typedef struct treeNode{
	int data; 
	nodeptr left, right;  
}treeNode;

nodeptr createTree(int); 

void inorder(nodeptr); 

void preorder(nodeptr); 

void postorder(nodeptr); 

int maxDepth(nodeptr); 

void insert(nodeptr* , int); 

nodeptr search(nodeptr root, int); 

int main(){
	
	// Examples
	
	nodeptr tree = NULL; 
	int i; 
	
	int sample[] = {23, 31, 19, 22, 27, 15, 40, 23, 29, 19}; 
	
	int size = sizeof(sample) / sizeof(sample[0]); 
	
	printf("\nThe values: "); 
	for(i = 0; i < size; i++){ 
		printf("%d ", sample[i]); 
	}
	printf("\n"); 
	
	for(i = 0; i < size; i++){		
		insert(&tree, sample[i]); 
	}
	
	printf("Inorder: "); 
	inorder(tree); 
	printf("\n"); 
	
	printf("Pre-order: "); 
	preorder(tree); 
	printf("\n"); 
	
	printf("Postorder: "); 
	postorder(tree); 
	printf("\n"); 
	
	printf("Height of tree: %d", maxDepth(tree)); 
	
	printf("\nNo. of Nodes: %d", size); 
	return 0; 
}

nodeptr createTree(int data){
	nodeptr node = (nodeptr)malloc(sizeof(treeNode)); 
	node->data = data; 
	node->left = node->right = NULL; 
	
	return node; 
}

void inorder(nodeptr root){
	if (root == NULL)
		return; 
		
	inorder(root->left); 
	printf("%d ", root->data); 
	inorder(root->right); 
}

void preorder(nodeptr root){
	if (root == NULL)
		return; 
		
	printf("%d ", root->data); 
	preorder(root->left); 
	preorder(root->right); 
}

void postorder(nodeptr root){
	if (root == NULL)
		return; 
		
	postorder(root->left); 
	postorder(root->right); 
	printf("%d ", root->data); 
}

int maxDepth(nodeptr root){
	if (root == NULL)
		return 0; 
		
	int lDepth = maxDepth(root->left); 
	int rDepth = maxDepth(root->right); 
	
	return (lDepth > rDepth)? lDepth+1 : rDepth+1; 
}

void insert(nodeptr* root, int data){
	if(*root == NULL){
		*root = createTree(data); 
		
	} else if((*root)->data > data || (*root)->data == data){
		insert(&(*root)->left, data); 
		
	} else if((*root)->data < data){
		insert(&(*root)->right, data); 
	}
}

nodeptr search(nodeptr root, int data){ 
	if(root != NULL){
		if(root->data == data){
			return root; 
		}
		else if(root->data > data){
			search(root->right, data); 
		}
		else if(root->data < data){
			search(root->left, data); 
		}
	}
	else {
		return NULL; 
	}
}
