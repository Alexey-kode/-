#include "Graph.h"

#include <iostream>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

bool Graph::hasVertex(const string& vertex) {
    return adjacencyList.find(vertex) != adjacencyList.end();
}

void Graph::addVertex(const string& vertex) {
    if (!hasVertex(vertex)) {
        adjacencyList[vertex] = vector<string>();
    }
}

void Graph::addEdge(const string& firstVertex, const string& secondVertex) {
    addVertex(firstVertex);
    addVertex(secondVertex);

    adjacencyList[firstVertex].push_back(secondVertex);
    adjacencyList[secondVertex].push_back(firstVertex);
}

void Graph::printGraph() const {
    cout << "Список смежности графа:" << endl;

    for (const auto& vertex : adjacencyList) {
        cout << vertex.first << ": ";

        for (const string& neighbor : vertex.second) {
            cout << neighbor << " ";
        }

        cout << endl;
    }
}

vector<string> Graph::bfs(const string& startVertex) {
    vector<string> result;
    map<string, bool> visited;
    queue<string> q;

    if (!hasVertex(startVertex)) {
        return result;
    }

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        result.push_back(current);

        for (const string& neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    return result;
}

vector<string> Graph::dfs(const string& startVertex) {
    vector<string> result;
    map<string, bool> visited;
    stack<string> s;

    if (!hasVertex(startVertex)) {
        return result;
    }

    s.push(startVertex);

    while (!s.empty()) {
        string current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            result.push_back(current);

            for (const string& neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    s.push(neighbor);
                }
            }
        }
    }

    return result;
}

vector<string> Graph::findPath(const string& startVertex, const string& endVertex) {
    vector<string> path;
    map<string, bool> visited;
    map<string, string> previous;
    queue<string> q;

    if (!hasVertex(startVertex) || !hasVertex(endVertex)) {
        return path;
    }

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (current == endVertex) {
            break;
        }

        for (const string& neighbor : adjacencyList[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                previous[neighbor] = current;
                q.push(neighbor);
            }
        }
    }

    if (!visited[endVertex]) {
        return path;
    }

    string current = endVertex;

    while (current != startVertex) {
        path.push_back(current);
        current = previous[current];
    }

    path.push_back(startVertex);
    reverse(path.begin(), path.end());

    return path;
}
