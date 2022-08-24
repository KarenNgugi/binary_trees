#include "binary_trees.h"

/**
 * binary_tree_depth - measures depth of node in binary tree
 * @tree: pointer to node to measure in depth
 * Return: depth of node, otherwise 0
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t left_depth = 0;
	// size_t right_depth = 0;
	// binary_tree_t *node = tree;

	if (tree == NULL)
		return (0);

	while (tree != NULL)
	{
		left_depth++;
		tree = tree->left;
	}
	return (left_depth);
}
