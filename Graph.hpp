#pragma once
#include <vector>

class Vertex
{
public:
    long id;
    Vertex(long id);
};

class Edge
{
public:
    Vertex start;
    Vertex end;
    double weight;
    Edge(Vertex start, Vertex end, double weight);
};

class Graph
{
public:
    std::vector<Vertex> vertices;
    std::vector<Edge> edges;
    Graph(){};
    Graph(std::vector<Vertex> vertices, std::vector<Edge> edges);
    void addVertex(Vertex vertex);
    void addEdge(Edge edge);
};
