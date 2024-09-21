#include <stdio.h>
#include <stdlib.h>

typedef struct	s_tree
{
	int		value;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

int binary_size(t_tree *root)
{
	if (root == NULL)
		return 0;
	return (binary_size(root->left) + binary_size(root->right) + 1);
} 

// int binary_size(t_tree *root)
// {
// 	int size_left;
// 	int size_right;
	
// 	size_left = 0;
// 	size_right = 0;
// 	if (root == NULL)
// 		return 0;
// 	size_left += binary_size(root->left);
// 	size_right += binary_size(root->right);
// 	return (size_left + size_right + 1);
// }

void	print_tree(t_tree *tree)
{
	if (tree == NULL)
	{
		printf("tree is empty\n");
		return ;
	}
	printf("%d\n", tree->value);
	printf("left\n");
	print_tree(tree->left);
	printf("right\n");
	print_tree(tree->right);
}

void print_tabs(int tabs)
{
	int i;

	i = 0;
	while (i < tabs)
	{
		printf("\t");
		i++;
	}
}

void print_tree_with_tabs(t_tree *tree, int tabs)
{
	if (tree == NULL)
	{
		print_tabs(tabs);
		printf("---\n");
		return ;
	}
	print_tabs(tabs);
	printf("-%d-\n", tree->value);
	print_tabs(tabs);
	printf("left\n");
	print_tree_with_tabs(tree->left, tabs + 1);
	print_tabs(tabs);
	printf("right\n");
	print_tree_with_tabs(tree->right, tabs + 1);
}

t_tree	*create_node(int value)
{
	t_tree	*new_node;

	new_node = (t_tree *)malloc(sizeof(t_tree));
	if (new_node == NULL)
		return (NULL);
	new_node->value = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return (new_node);
}

int main()
{
	t_tree *n1 = create_node(1);
	t_tree *n2 = create_node(2);
	t_tree *n3 = create_node(3);
	t_tree *n4 = create_node(4);
	t_tree *n5 = create_node(5);

	n1->left = n2;
	n1->right = n3;
	n3->left = n4;
	n3->right = n5;

	// print_tree(n1);
	print_tree_with_tabs(n1, 0);
	printf("\n");
	printf("size: %d\n", binary_size(n1));
	return (0);
}


// 	      1
//  	/	
//    2	     3
// 	       /	
//       4		 5	


// Implement a function that culculates the size of a binary tree,
// that is to say, the total number of nodes it contains.

// The function should be declared as follows:
// int size_binary_tree(t_btree *root);

// You have to use the ft_btree.h file, which will ONLY contain:

// typedef struct  s_btree
// {
//     int     value;
//     struct s_btree  *left;
//     struct s_btree  *right;
// }               t_btree;

// if the root node is NULL, return 0.