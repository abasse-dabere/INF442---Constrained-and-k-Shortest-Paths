#ifndef SHORTEST_PATH_HPP
#define SHORTEST_PATH_HPP

#include <vector>
#include <unordered_map>
#include "graph.hpp"

class ShortestPathSequential {
public:
    static std::unordered_map<int, int> dijkstra(const Graph& graph, int source); 
    static std::unordered_map<int, int> bellman_ford(const Graph& graph, int source);
};

class ShortestPathParallel {
public:
    static std::unordered_map<int, int> dijkstra(const Graph& graph, int source);
};

#endif // SHORTEST_PATH_HPP
