// allowed funcs: malloc, free

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>


typedef struct s_binary
{
    int value;
    struct s_binary *left;
    struct s_binary *right;
} t_btree;


t_btree *binary_mirror(const t_btree *root)
{
    t_btree *left;
    t_btree *right;
    t_btree *temp;
    int l_val;
    int r_val;
    t_btree *curr;

    if (root == NULL)
        return (NULL);
    curr = (t_btree *)root;
    left = binary_mirror(curr->left);
    right = binary_mirror(curr->right);

    temp  = curr->left;
    curr->left= curr->right;
    curr->right = temp;

    return (curr);
}


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
    binary_mirror(tree3);
    print_tree(tree3, 0);
    return (0);
}