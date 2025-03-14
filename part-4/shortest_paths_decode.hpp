#ifndef __shortest_paths_decode__
#define __shortest_paths_decode__

#include "graph.hpp"
#include <algorithm>
#include <vector>

inline std::vector<int> decode(const std::vector<hop_t>& DP_u, int v)
{
    // WRITE YOUR CODE HERE
    std::vector<int> path;

    // empty path for unreachable vertices and source vertex
    if (DP_u[v].weight == inf || DP_u[v].vertex == -1) {
        return path;
    }

    while (v != -1) {
        path.push_back(v);
        v = DP_u[v].vertex;
    }

    std::reverse(path.begin(), path.end());
    return path;
}

#endif // __shortest_paths_decode__
