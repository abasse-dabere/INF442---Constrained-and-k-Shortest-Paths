#include "graph.hpp"
void Graph::add_node(int node) {
        if (adjacency_list.find(node) == adjacency_list.end()) {
            adjacency_list[node] = std::vector<std::pair<int, int>>();
        }
    }

    void Graph::add_edge(int from, int to, int weight) {
        add_node(from);
        add_node(to);
        adjacency_list[from].push_back(std::make_pair(to, weight));
    }

 std::unordered_map<int, std::vector<std::pair<int, int>>> Graph::get_adjacency_list() const{
        return adjacency_list;
    }