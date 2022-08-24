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
 * binary_tree_levelorder - goes through binary tree using level-order 
 * traversal
 * @tree: pointer to root node of tree
 * @func: pointer to function to call on each node
 * Return: nothing
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t height = binary_tree_height(tree), i = 1;

	if ((tree == NULL) || (func == NULL))
		return;

	for (i = 1; i <= height; i++)
		binary_tree_levelorder(tree, func);
}