#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_map>
#include <vector>

class Graph {
private:
    std::unordered_map<int, std::vector<std::pair<int, int>>> adjacency_list;

public:
    void add_node(int node);

    void add_edge(int from, int to, int weight);

    std::unordered_map<int, std::vector<std::pair<int, int>>> get_adjacency_list()const;
};

#endif