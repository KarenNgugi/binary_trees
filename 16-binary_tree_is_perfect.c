#include "binary_trees.h"

/**
 * binary_tree_size - measures size of binary tree
 * @tree: pointer to root node of tree to be measured
 * Return: size of tree, otherwise 0
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size = 0;
	size_t right_size = 0;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}

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

	if ((tree->left == NULL) && (tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * exponent - helper function to compute exponent
 * @a: first number
 * @b: second number
 * Return: result of exponentiation
 */
int exponent(int a, int b)
{
	int pow = 1, i = 0;

	if (b < 0)
		return (-1);

	if (b == 1)
		return (1);

	for (i = 0; i < b; i++)
		pow *= a;

	return (pow);
}


/**
 * binary_tree_is_perfect - checks if binary tree is perfect
 * @tree: pointer to root node of tree to be checked
 * Return: 1 if true, 0 otherwise
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height, nodes;

	if (tree == NULL)
		return (0);

	height = binary_tree_height(tree);
	nodes = binary_tree_size(tree);

	if (nodes == exponent(2, height) - 1)
		return (1);
	else
		return (0);
}
