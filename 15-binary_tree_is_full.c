#include "binary_trees.h"

int binary_tree_is_full(const binary_tree_t *tree)
{
    int left, right;
    if (!tree)
        return (0);
    if (!tree->right && !tree->left)
        return (1);
    left = binary_tree_is_full(tree->left);
    right = binary_tree_is_full(tree->right);
    if (left == 0 || right == 0)
        return (0);
    return (1);
}
