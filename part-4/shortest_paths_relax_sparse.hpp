#ifndef __shortest_paths_relax_sparse__
#define __shortest_paths_relax_sparse__

#include "graph.hpp"
#include <vector>

inline bool relax_sparse(const SparseGraph& graph, std::vector<hop_t>& DP, int r, int v)
{
    auto Duv = DP[v].weight;
    for (const auto& hop : graph[r]) {
        if (hop.vertex == v) {
            auto Duv_via_r = DP[r].weight + hop.weight;
            if (Duv_via_r < Duv) {
                DP[v] = {Duv_via_r, r};
                return true;
            }
            break;  // edge (r, v) is unique
        }
    }
    return false;
}

#endif // __shortest_paths_relax_sparse__