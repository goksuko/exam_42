#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_binary
{
    int value;
    struct s_binary *left;
    struct s_binary *right;
} t_btree;

int tree_size(t_btree *root)
{
    int left;
    int right;

    if (root == NULL)
        return (0);
    left = tree_size(root->left);
    right = tree_size(root->right);
    return (left + right + 1);
}

int tree_height(t_btree *root)
{
    int left;
    int right;
    int height;

    if (root == NULL)
        return (0);
    left = tree_height(root->left);
    right = tree_height(root->right);

    if (right > left)
        height = right;
    else
        height = left;
    return (height + 1);
}

t_btree *mirror(t_btree *root)
{
    t_btree *left;
    t_btree *right;
    t_btree *temp;

    if (root == NULL)
        return (NULL);
    left = mirror(root->left);
    right = mirror(root->right);
    temp  = root->left;
    root->left= root->right;
    root->right = temp;
    return (root);
}

// t_btree *append(t_btree *root, int value, char direction)
// {
//     t_btree *node;
//     t_btree *curr;

//     node = malloc(sizeof(t_btree));
//     if (node == NULL)
//         return (NULL);
//     node->value = value;
//     node->left = NULL;
//     node->right = NULL;
//     curr = root;
//     if (root == NULL)
//         return (node);
//     else if (direction == 'L')
//     {
//         while (curr->left != NULL)
//             curr = curr->left;
//         curr->left = node;
//     }
//     else
//     {
//         while (curr->right != NULL)
//             curr = curr->right;
//         curr->right = node;
//     }
//     return (root);
// }

t_btree *new_node(int value)
{
    t_btree *node;

    node = malloc(sizeof(t_btree));
    if (node == NULL)
        return (NULL);
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return (node);
}

t_btree *make_tree3()
{
    t_btree *tree; // size = 11, height = 6

	tree = new_node(1);
	tree->left = new_node(2);
	tree->left->left = new_node(3);
	tree->left->left->right = new_node(4);
	tree->left->right = new_node(5);
	tree->left->right->right = new_node(6);
	tree->left->right->right->right = new_node(7);
	tree->left->right->right->right->right = new_node(8);
	tree->right = new_node(9);
	tree->right->right = new_node(10);
	tree->right->right->left = new_node(11);
    return (tree);
}

void print_tree(t_btree *tree, int spaces) {
	if (!tree) {
		write(1, "\n", 1);
		return ;
	}
	spaces += 5;
	print_tree(tree->right, spaces);
	printf("\n");
	for (int i = 0; i < spaces; i++)
		printf(" ");
	printf("%d\n", tree->value);
	print_tree(tree->left, spaces);
}


void print_bst(t_btree* root, int level, char *prefix)
{
    if (root == NULL)
        return ;
    int spaces = 4;
    char indent[spaces + 1];
    for (int i = 0; i < spaces; i++) {
        indent[i] = ' ';
    }
    indent[spaces] = '\0';

    if (level == 0)
        printf("%s%d\n", prefix, root->value);
    else
        printf("%*s|__ %d\n", spaces * level, indent, root->value);
    char left_prefix[6] = "L--- ";
    char right_prefix[6] = "R--- ";
    print_bst(root->left, level + 1, left_prefix);
    print_bst(root->right, level + 1, right_prefix);

}

int main()
{
    t_btree *tree3;

	tree3 = make_tree3();

    // print_bst(tree3, 0, "Root: ");
    // printf("\n\n\n\n");
    print_tree(tree3, 0);
    printf("size: %d\n", tree_size(tree3));
    printf("height: %d\n", tree_height(tree3));
    mirror(tree3);
    print_tree(tree3, 0);
    return (0);
}