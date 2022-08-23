#include "binary_trees.h"

/**
 * binary_tree_depth - measures depth of node in binary tree
 * @tree: pointer to node to measure in depth
 * Return: depth of node, otherwise 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	if ((tree->left == NULL) && (tree->right == NULL))
		return (0);

	left_height = binary_tree_depth(tree->left);
	right_height = binary_tree_depth(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}
