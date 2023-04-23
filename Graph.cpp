#include <Graph.hpp>
#include <vector>

class Vertex
{
public:
    long id;
    Vertex(long id) : id(id) {}
};

class Edge
{
public:
    Vertex start;
    Vertex end;
    double weight;
    Edge(Vertex start, Vertex end, double weight) : start(start), end(end), weight(weight) {}
};

class Graph
{
public:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    Graph(){};
    Graph(std::vector<Vertex> vertices, std::vector<Edge> edges) : vertices(vertices), edges(edges) {}
    void addVertex(Vertex vertex)
    {
        vertices.push_back(vertex);
    }
    void addEdge(Edge edge)
    {
        edges.push_back(edge);
    }
    void addEdge(Vertex start, Vertex end, double weight)
    {
        Edge edge(start, end, weight);
        edges.push_back(edge);
    }
};

int main(int argc, char const *argv[])
{
    return 0;
}
