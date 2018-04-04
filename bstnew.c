//bstnew

#include <stdlib.h>
#include <stdio.h>
#define COUNT 10

typedef struct BSTnodeList{
	int data;
	struct BSTnodeList* next;
}BSTnodeList;

typedef struct binaryNode{
	int data;
	struct binaryNode* left;
	struct binaryNode* right;
}binaryNode;



BSTnodeList* push(BSTnodeList* node, int data){
	BSTnodeList* temp = (BSTnodeList*)malloc(sizeof(struct BSTnodeList));
	temp->data = data; 
	temp->next = node;
	node = temp;
		
}
BSTnodeList* pop(BSTnodeList* node){
	BSTnodeList* temp = (BSTnodeList*)malloc(sizeof(struct BSTnodeList));
	temp = node;
	node = node->next;
	free(temp);
}


/********* CREATE BST ******/

binaryNode* getNewNode(int data){ //returns node address, no need node args
	binaryNode* temp = (binaryNode*)malloc(sizeof(struct binaryNode));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp; 
}

binaryNode* insertBST(binaryNode* root, int data){
	if(root == NULL){
		root = getNewNode(data);}
	else if(data <= root->data){
		root->left = insertBST(root->left, data);}
	else if(data >= root->data){
		root->right = insertBST(root->right, data);}
	return root;
}


void preorder(binaryNode* root);
void inorder(binaryNode* root);
void postorder(binaryNode* root);
void BST_to_array(binaryNode* root);
void print2d(binaryNode* root);
void print2dutil(binaryNode* root, int space);
///////////////////////////////////////////
// goal here is to convert a BST to a linkedlist or array. ll for this case 

void main(){
	BSTnodeList* head = NULL;
	binaryNode* root = NULL;int size = 100; 
	root = insertBST(root, 3);
	root = insertBST(root,1);	
	root = insertBST(root,5);	
	root = insertBST(root,2);
	root = insertBST(root,4);
	root = insertBST(root,5);
	root = insertBST(root,6);	
	print2d(root);
	scanf("%u\n");
}
void print2DUtil(binaryNode* root, int space){
	// Base case
    if (root == NULL)
        return;
 
    // Increase distance between levels
    space += COUNT;
 
    // Process right child first
    print2DUtil(root->right, space);
 
    // Print current node after space
    // count
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d\n", root->data);
 
    // Process left child
    print2DUtil(root->left, space);
}
void print2d(binaryNode* root){
	print2DUtil(root,0);
}



int size = 100;

void BST_to_array(binaryNode* root){
	int array[size]; 
	if(root == NULL) return;
	for(int i = 0; i<size; i++)
	{		
		array[i] = root->data;
		BST_to_array(root->left);
		//BST
	}
	
}

void preorder(binaryNode* root){
	if (root == NULL) return;
	printf("data is %u\n", root->data);
	preorder(root->left);
	preorder(root->right);
}
void inorder(binaryNode* root){
	if (root == NULL) return;
	preorder(root->left);
	printf("data is %u\n", root->data);
	preorder(root->right);
}







