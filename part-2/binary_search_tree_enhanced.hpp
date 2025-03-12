#ifndef __binary_saerch_tree_enhanced__
#define __binary_saerch_tree_enhanced__

#include "binary_search_tree.hpp"

template <typename T>
T bst_min(const T& tree)  // T: reference to a pointer "tree"
{
    // WRITE YOUR CODE HERE
    T tree_min = tree;
    while (left(tree_min))
        tree_min = left(tree_min);
    return tree_min;
}

template <typename T> 
T bst_max(const T& tree)
{
    // WRITE YOUR CODE HERE
    T tree_max = tree;
    while (right(tree_max))
        tree_max = right(tree_max);
    return tree_max;
}

#endif // __binary_saerch_tree_enhanced__