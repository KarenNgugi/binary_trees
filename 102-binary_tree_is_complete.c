#include "binary_trees.h"

/**
 * binary_tree_height - measure height of binary tree
 * @tree: pointer to root node of tree
 * Return: 0 if tree is NULL, otherwise return the height
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_nodes - counts nodes with at least 1 child
 * @tree: pointer to root node of tree to be checked
 * Return: number of nodes, otherwise 0
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes = 0;
	size_t right_nodes = 0;

	if (tree == NULL)
		return (0);

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	return (left_nodes + right_nodes + 1);
}

/**
 * exponent - helper function to calculate exponent of two numbers
 * @a: first number
 * @b: second number
 * Return: result of exponentiation
 */
int exponent(int a, int b)
{
	int power = 1;
	int i = 0;

	for (i = 0; i < b; i++)
		power *= a;

	return (power);
}


/**
 * binary_tree_is_complete - checks if binary tree is complete
 * @tree: root node of tree to check
 * Return: 1 if true, otherwise 0
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	int height;
	int nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	nodes = binary_tree_nodes(tree);

	if (nodes == exponent(2, height) - 1)
		return (1);
	else
		return (0);
}
