#include "binary_trees.h"

/**
 * @brief
 *
 * @param tree
 * @return size_t
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
    size_t lfleaves, rtleaves;

    if (!tree)
        return (0);
    if (!tree->left && !tree->right)
        return (1);

    lfleaves = binary_tree_leaves(tree->left);
    rtleaves = binary_tree_leaves(tree->right);
    return (lfleaves + rtleaves);
}
