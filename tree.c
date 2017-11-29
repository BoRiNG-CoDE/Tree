#include <stdio.h>
#include <malloc.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;

}node;

node *create()
{
	node *p;
	int x;

	printf("\nEnter The Data(-1 for NO Data): ");
	scanf("\n%d",&x);

	if(x == -1)
		return NULL;
	
	p = (node *)malloc(sizeof(node));
	p->data=x;
	
	printf("\nEnter Left child of %d ",x);
	p->left=create();

	printf("\nEnter Right child of %d ",x);
	p->right=create();

	return p;


}
//function for preorder
/*
void PreOrder(node *t)
{
	if(t)
	{
		printf("\n %d",t->data);
		PreOrder(t->left);
		PreOrder(t->right);
	}
}
*/

//this function is for Searching open the comment and try it
/*
node *search_tree(node *t,int choice)
{
	
	if(t)
	{
		if(t->data == choice)
		{
			return t;
			
		}

		else
		{
			if(t->data < choice)
				search_tree(t->right,choice);
			else
				search_tree(t->left,choice);
		}
	}
}
*/

int totalTre(node *t)
{
	if(t==NULL)
		return 0;
	else
		return(totalTre(t->left)+totalTre(t->right)+1);
		
	
}

int height_tree(node *t)
{
	if(t==NULL)
		return -1;
	else
	{
		int left_height = height_tree(t->left);
		int right_height = height_tree(t->right);

		if(left_height > right_height)
			return left_height+1;
		else
			return right_height+1;
	}
}

int internal_Node(node *t)
{
	if((t == NULL) || (t->left == NULL && t->right == NULL))
		return 0;
	else
		return(internal_Node(t->left) + internal_Node(t->right) +1);

}

int ext_Tree(node *t)
{
	if((t == NULL) || (t->left == NULL) && (t->right) == NULL)
		return 1;
	else
		return (ext_Tree(t->left) + ext_Tree(t->right));
}

node *smallest(node *t)
{
	if(t == NULL || t->left == NULL)
		return t;
	else
		return (smallest(t->left));
}

int main()
{

	node *root,*root2;
	root=create();
	
	/*int choice;
	printf("\nEnter the Number To be Searched: ");
	scanf("\n%d",&choice);

	root2= search_tree(root,choice);		//for Searching Element in a Tree
	if(root2)
		printf("\nFound\n");
	*/
	/*printf("\nPrint The Tree in PreOrder:\n");		//print the tree in Preorder
	PreOrder(root);*/

	//total Number of Nodes in Tree
	int val =totalTre(root);
	printf("\nToatl Number of Nodes are: %d\n ",val);

	//height of Tree
	int height =height_tree(root);
	printf("\nHeight of tree is: %d\n",height);

	//Internal Nodes (Non-Leaf Nodes)in a Tree
	int internal_node = internal_Node(root);
	printf("\nInternal Node(NON-LEAF NODE) is: %d\n",internal_node);

	//External Nodes (LEAF NODES) in a Tree
	int ext_tree = ext_Tree(root);
	printf("\nExternal Nodes (Leaf Nodes ) are: %d\n",ext_tree);

	//smallest in the Tree
	root2 = smallest(root);
	printf("\n smallest o. is: %d\n",root2->data);

	return 0;
}