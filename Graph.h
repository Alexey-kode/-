#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class Graph {
private:
    map<string, vector<string>> adjacencyList;

public:
    bool hasVertex(const string& vertex);

    void addVertex(const string& vertex);

    void addEdge(const string& firstVertex, const string& secondVertex);

    void printGraph() const;

    vector<string> bfs(const string& startVertex);

    vector<string> dfs(const string& startVertex);

    vector<string> findPath(const string& startVertex, const string& endVertex);
};

#endif
