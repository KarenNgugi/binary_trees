#include "binary_trees.h"

/**
 * binary_tree_insert_left - insert a node as a left child
 * @parent: parent node of the node to be created
 * @value: value of the new node
 * Return: pointer to new node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node = malloc(sizeof(binary_tree_t));

	if (node == NULL)
	{
		free(node);
		return (NULL);
	}

	if (parent == NULL)
		return (NULL);

	node->n = value;
	node->parent = parent;
	node->left = NULL;
	node->right = NULL;

	if (parent->left)
	{
		node->left = parent->left;
		parent->left->parent = node;
		parent->left = node;
	}
	else
		parent->left = node;

	return (node);
	free(node);
}
