#include "binary_trees.h"

/**
 * binary_tree_rotate_left - performs left rotation on binary tree
 * @tree: pointer to root node of tree
 * Return: pointer to new root node of tree once rotated
 */

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
	{
		return (NULL);
		free(node);
	}

	if (tree == NULL )
		return (tree);

	if ((tree->left == NULL) && (tree->right == NULL))
		return (tree);

	node = binary_tree_rotate_left(tree->left);

	tree->left->left = tree->right;
	tree->left->right = tree;
	tree->left = NULL;
	tree->right = NULL;

	return (node);
}
