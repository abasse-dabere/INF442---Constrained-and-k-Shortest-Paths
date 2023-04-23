#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>
#include "shortest_path.hpp"

std::unordered_map<int, int> ShortestPathSequential::dijkstra(const Graph& graph, int source) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::unordered_map<int, int> distance;
    for (const auto& node : graph.get_adjacency_list()) {
        distance[node.first] = std::numeric_limits<int>::max();
    }

    distance[source] = 0;
    pq.push(std::make_pair(0, source));

    while (!pq.empty()) {
        int current_node = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        if (current_distance > distance[current_node]) {
            continue;
        }

        for (const auto& neighbor : graph.get_adjacency_list().at(current_node)) {
            int neighbor_node = neighbor.first;
            int neighbor_distance = neighbor.second;

            int new_distance = distance[current_node] + neighbor_distance;

            if (new_distance < distance[neighbor_node]) {
                distance[neighbor_node] = new_distance;
                pq.push(std::make_pair(new_distance, neighbor_node));
            }
        }
    }

    return distance;
}

std::unordered_map<int, int> ShortestPathSequential::bellman_ford(const Graph& graph, int source) {
    std::unordered_map<int, int> distance;
    for (const auto& node : graph.get_adjacency_list()) {
        distance[node.first] = std::numeric_limits<int>::max();
    }

    distance[source] = 0;

    for (int i = 0; i < graph.get_adjacency_list().size() - 1; ++i) {
        for (const auto& node : graph.get_adjacency_list()) {
            int u = node.first;
            for (const auto& neighbor : node.second) {
                int v = neighbor.first;
                int weight = neighbor.second;
                if (distance[u] + weight < distance[v]) {
                    distance[v] = distance[u] + weight;
                }
            }
        }
    }

    for (const auto& node : graph.get_adjacency_list()) {
        int u = node.first;
        for (const auto& neighbor : node.second) {
            int v = neighbor.first;
            int weight = neighbor.second;
            if (distance[u] + weight < distance[v]) {
                std::cerr << "Graph contains negative weight cycle!" << std::endl;
                std::exit(1);
            }
        }
    }

    return distance;
}