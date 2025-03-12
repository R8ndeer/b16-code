#ifndef __binary_saerch_tree_enhanced__
#define __binary_saerch_tree_enhanced__

#include "binary_search_tree.hpp"

template <typename T>
T bst_min(const T& tree)  // T: reference to a pointer "tree"
{
    // WRITE YOUR CODE HERE
    if (!left(tree))
        return tree;
    return bst_min(left(tree));
}

template <typename T> 
T bst_max(const T& tree)
{
    // WRITE YOUR CODE HERE
    if (!right(tree))
        return tree;
    return bst_max(right(tree));
}

#endif // __binary_saerch_tree_enhanced__