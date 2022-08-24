#include "binary_trees.h"

/**
 * binary_tree_is_bst - checks if binary tree is valid Binary Search Tree
 * @tree: pointer to root node of tree
 * Return: 1 if tree is valid BST, 0 if it's not or if it's NULL
 */

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if ((tree->left != NULL) && (tree->left->n > tree->n))
		return (0);

	if ((tree->right != NULL) && (tree->right->n < tree->n))
		return (0);

	if (!binary_tree_is_bst(tree->left) || !binary_tree_is_bst(tree->right))
		return (0);

	return (1);
}
