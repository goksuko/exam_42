#include <stdio.h>
#include <stdlib.h>

typedef struct	s_tree
{
	int		value;
	struct s_tree	*left;
	struct s_tree	*right;
}				t_tree;

int height_tree(t_tree *tree)
{
	int left_height;
	int right_height;

	if (tree == NULL)
		return (0);
	left_height = height_tree(tree->left);
	right_height = height_tree(tree->right);
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

// int height_binary_tree(t_tree *root)
// {
//     int height_left;
//     int height_right;
    
//     height_left = 0;
//     height_right = 0;
//     if (root == NULL)
//         return (0);
//     while (root)
//     {
//         height_left += height_binary_tree(root->left);
//         height_right += height_binary_tree(root->right);
//         if (height_left >= height_right)
//             return (height_left + 1);
//         return (height_right + 1);
//     }
//     return (-1);
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
	printf("height: %d\n", height_tree(n1));
	return (0);
}


// 	      1
//  	/	
//    2	     3
// 	       /	
//       4		 5	