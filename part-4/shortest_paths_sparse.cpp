#include "shortest_paths_sparse.hpp"
#include "shortest_paths_relax_sparse.hpp"
#include <priority_queue.hpp>

#include <cmath>

std::vector<hop_t> bellman_ford(const SparseGraph& graph, const int source,
                                bool& has_negative_cycle)
{
    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});

    // WRITE YOUR CODE HERE
    assert(0 <= source && source < V);
    DP[source].weight = 0;

    for (int iter = 0; iter < V - 1; ++iter) {
        has_negative_cycle = false;
        for (int r = 0; r < V; ++r) {
            for (int v = 0; v < V; ++v) {
                has_negative_cycle |= relax_sparse(graph, DP, r, v);
            }
        }
    }

    return DP;
}

struct triplet_t {
    float d;
    int r;
    int v;
};

std::vector<hop_t> dijkstra(const SparseGraph& graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    auto DP = std::vector<hop_t>(graph.size(), {inf, -1});

    // WRITE YOUR CODE HERE
    DP[source].weight = 0;

    auto queue = std::vector<hop_t>{};
    auto comparison = std::less<hop_t>{}; // for a min-priority queue
    priority_enqueue(queue, {0, source}, comparison);

    while (!queue.empty()) {
        auto v_star = queue[0].vertex;
        priority_dequeue(queue, comparison);

        for (const auto& hop : graph[v_star]) {
            auto v = hop.vertex;
            if (relax_sparse(graph, DP, v_star, v)) {
                priority_enqueue(queue, {DP[v].weight, v}, comparison);
            }
        }
    }

    return DP;
}
