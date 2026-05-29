#ifndef GRAPH_H // проверяем, не был ли уже подключён этот заголовочный файл
#define GRAPH_H

#include <string> // подключаем библиотеку для работы со строками
#include <vector> // подключаем библиотеку для работы с динамическими массивами
#include <map> // подключаем библиотеку для хранения данных в виде ключ-значение

using namespace std; // подключаем стандартное пространство имён

class Graph { // объявляем класс Graph для работы с графом
private: // закрытая часть класса
    map<string, vector<string>> adjacencyList; // список смежности: вершина и список её соседей

public: // открытая часть класса
    bool hasVertex(const string& vertex); // объявляем метод проверки существования вершины

    void addVertex(const string& vertex); // объявляем метод добавления вершины

    void addEdge(const string& firstVertex, const string& secondVertex); // объявляем метод добавления ребра

    void printGraph() const; // объявляем метод вывода графа

    vector<string> bfs(const string& startVertex); // объявляем метод обхода графа в ширину

    vector<string> dfs(const string& startVertex); // объявляем метод обхода графа в глубину

    vector<string> findPath(const string& startVertex, const string& endVertex); // объявляем метод поиска пути
}; // завершаем описание класса Graph

#endif // завершаем защиту от повторного подключения
