#include <stdio.h>
#include <stdlib.h>

typedef struct	s_tree
{
	int		value;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

t_tree	*invert_binary(t_tree *root)
{
	t_tree *temp;
	
	if (root == NULL)
		return NULL;
	root->left = invert_binary(root->left);
	root->right = invert_binary(root->right);
	temp = root->left;
	root->left = root->right;
	root->right = temp;

	return (root);
}

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
	n1 = invert_binary(n1);
	printf("after_invertion: \n");
	print_tree_with_tabs(n1, 0);
	return (0);
}


// 	      1
//  	/	
//    2	     3
// 	       /	
//       4		 5	