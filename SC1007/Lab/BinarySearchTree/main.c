//////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

///////////////////////////////////////////////////////////////////////

typedef struct _btnode{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;

///////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value);
void printBSTInOrder(BTNode *node);
int isBST(BTNode *node, int min, int max);
BTNode *removeBSTNode(BTNode *node, int value);
BTNode *findMin(BTNode *p);

///////////////////////////////////////////////////////////////////////

int main(){
	int i=0;

	BTNode *root=NULL;

	//question 1
	do{
		printf("input a value you want to insert(-1 to quit):");

		scanf("%d",&i);
		if (i!=-1)
			insertBSTNode(&root,i);
	}while(i!=-1);

	//question 2
	printf("\n");
	printBSTInOrder(root);

	//question 3
	if ( isBST(root,-1000000, 1000000)==1)
		printf("It is a BST!\n");
	else
		printf("It is not a BST!\n");

	//question 4
	do{
		printf("\ninput a value you want to remove(-1 to quit):");
		scanf("%d",&i);
		if (i!=-1)
		{
			root=removeBSTNode(root,i);
			printBSTInOrder(root);
		}
	}while(i!=-1);


	return 0;
}

//////////////////////////////////////////////////////////////////////

void insertBSTNode(BTNode **node, int value)
{
	// write your code here

    if(*node == NULL){
        *node = malloc(sizeof(BTNode));
        (*node)->item = value;
        (*node)->left = NULL;
        (*node)->right = NULL;
        return;
    }

	if ((*node)->item > value){
        insertBSTNode(&((*node)->left), value);
	} else if (value > ((*node)->item)){
        insertBSTNode(&((*node)->right), value);
	} else {
		printf("Already exists in the BST\n");
		return;
	}
	return;
}

//////////////////////////////////////////////////////////////////////

void printBSTInOrder(BTNode *node)
{
	// write your code here
	if(node == NULL) return;
	printBSTInOrder(node->left);
	printf("%d ", node->item);
	printBSTInOrder(node->right);

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int isBST(BTNode *node, int min, int max) // the item stored in node has to be smaller than max and larger than min
{
	// write your code here
	if (node == NULL) return 1;

	if(node->item < min || node->item > max) return 0;


	return isBST(node->left,min, node->item)&& isBST(node->right,node->item, max) ;




}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *removeBSTNode(BTNode *node, int value)
{
	// write your code here
	BTNode *p;

	if (node==NULL)
	{
		printf("can't find the value!\n");
		return NULL;
	}

	if (node->item >value) //go left tree
		 node->left = removeBSTNode(node->left, value);

	else if (node->item <value) //go right tree
		 node->right = removeBSTNode(node->right, value);

	else// if ((*node)->item ==value) found the node!
		if (node->left!=NULL && node->right !=NULL ) //*node has two children
		{
			p=findMin(node->right);
			node->item =p->item;
			node->right = removeBSTNode(node->right,p->item );
		}
		else //x has no children or one child
		{
			p=node;

			if (node->left !=NULL)
				node=node->left;
			else
				node=node->right;

			free(p);
		}
	return node;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

BTNode *findMin(BTNode *p)
{
	// write your code here
	if (p->left != NULL){
        return findMin(p->left);
	} else {
        return p;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
