#include <iostream>
#include <vector>
#include <string>
#include "Graph.h"

using namespace std;

void printVector(const vector<string>& data) {
    if (data.empty()) {
        cout << "Результат отсутствует";
    } else {
        for (const string& item : data) {
            cout << item << " ";
        }
    }

    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    Graph graph;

    graph.addEdge("A", "B");
    graph.addEdge("A", "C");
    graph.addEdge("B", "D");
    graph.addEdge("C", "E");
    graph.addEdge("D", "E");

    graph.printGraph();

    cout << endl;

    cout << "Обход BFS от вершины A: ";
    printVector(graph.bfs("A"));

    cout << "Обход DFS от вершины A: ";
    printVector(graph.dfs("A"));

    cout << "Путь от A до E: ";
    printVector(graph.findPath("A", "E"));

    cout << "Путь от A до F: ";
    printVector(graph.findPath("A", "F"));

    return 0;
}
