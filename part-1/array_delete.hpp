#ifndef __array_delete__
#define __array_delete__

#include <cstddef>
#include <cassert>
#include <utility>
#include <vector>

template <typename T>
void array_delete(std::vector<T> &A, std::size_t index)
{
    // WRITE YOUR CODE HERE
    assert(index < A.size());
    for (auto i = index; i < A.size() - 1; ++i)
        A[i] = A[i+1];
    A.pop_back();
}

#endif // __array_delete__