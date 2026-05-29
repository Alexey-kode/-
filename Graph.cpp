#include "Graph.h" // подключаем заголовочный файл с описанием класса Graph

#include <iostream> // подключаем библиотеку для вывода данных
#include <queue> // подключаем библиотеку для очереди
#include <stack> // подключаем библиотеку для стека
#include <algorithm> // подключаем библиотеку для функции reverse

using namespace std; // подключаем стандартное пространство имён

bool Graph::hasVertex(const string& vertex) { // реализуем метод проверки существования вершины
    return adjacencyList.find(vertex) != adjacencyList.end(); // возвращаем true, если вершина найдена
} // завершаем метод hasVertex

void Graph::addVertex(const string& vertex) { // реализуем метод добавления вершины
    if (!hasVertex(vertex)) { // проверяем, что такой вершины ещё нет
        adjacencyList[vertex] = vector<string>(); // добавляем вершину с пустым списком соседей
    } // завершаем условие
} // завершаем метод addVertex

void Graph::addEdge(const string& firstVertex, const string& secondVertex) { // реализуем метод добавления ребра
    addVertex(firstVertex); // добавляем первую вершину, если её ещё нет
    addVertex(secondVertex); // добавляем вторую вершину, если её ещё нет
    adjacencyList[firstVertex].push_back(secondVertex); // добавляем вторую вершину в список соседей первой
    adjacencyList[secondVertex].push_back(firstVertex); // добавляем первую вершину в список соседей второй
} // завершаем метод addEdge

void Graph::printGraph() const { // реализуем метод вывода графа
    cout << "Список смежности графа:" << endl; // выводим заголовок

    for (const auto& vertex : adjacencyList) { // перебираем все вершины графа
        cout << vertex.first << ": "; // выводим название текущей вершины

        for (const string& neighbor : vertex.second) { // перебираем всех соседей текущей вершины
            cout << neighbor << " "; // выводим одного соседа
        } // завершаем перебор соседей

        cout << endl; // переходим на новую строку
    } // завершаем перебор вершин
} // завершаем метод printGraph

vector<string> Graph::bfs(const string& startVertex) { // реализуем обход графа в ширину
    vector<string> result; // создаём список для хранения результата обхода
    map<string, bool> visited; // создаём карту посещённых вершин
    queue<string> q; // создаём очередь для алгоритма BFS

    if (!hasVertex(startVertex)) { // проверяем, существует ли стартовая вершина
        return result; // если вершины нет, возвращаем пустой результат
    } // завершаем условие

    visited[startVertex] = true; // отмечаем стартовую вершину как посещённую
    q.push(startVertex); // добавляем стартовую вершину в очередь

    while (!q.empty()) { // выполняем цикл, пока очередь не пустая
        string current = q.front(); // берём первую вершину из очереди
        q.pop(); // удаляем эту вершину из очереди

        result.push_back(current); // добавляем текущую вершину в результат обхода

        for (const string& neighbor : adjacencyList[current]) { // перебираем соседей текущей вершины
            if (!visited[neighbor]) { // проверяем, был ли сосед уже посещён
                visited[neighbor] = true; // отмечаем соседа как посещённого
                q.push(neighbor); // добавляем соседа в очередь
            } // завершаем условие
        } // завершаем перебор соседей
    } // завершаем цикл BFS

    return result; // возвращаем результат обхода
} // завершаем метод bfs

vector<string> Graph::dfs(const string& startVertex) { // реализуем обход графа в глубину
    vector<string> result; // создаём список для хранения результата обхода
    map<string, bool> visited; // создаём карту посещённых вершин
    stack<string> s; // создаём стек для алгоритма DFS

    if (!hasVertex(startVertex)) { // проверяем, существует ли стартовая вершина
        return result; // если вершины нет, возвращаем пустой результат
    } // завершаем условие

    s.push(startVertex); // добавляем стартовую вершину в стек

    while (!s.empty()) { // выполняем цикл, пока стек не пустой
        string current = s.top(); // берём верхнюю вершину из стека
        s.pop(); // удаляем эту вершину из стека

        if (!visited[current]) { // проверяем, была ли текущая вершина посещена
            visited[current] = true; // отмечаем текущую вершину как посещённую
            result.push_back(current); // добавляем текущую вершину в результат обхода

            for (const string& neighbor : adjacencyList[current]) { // перебираем соседей текущей вершины
                if (!visited[neighbor]) { // проверяем, был ли сосед посещён
                    s.push(neighbor); // добавляем непосещённого соседа в стек
                } // завершаем условие
            } // завершаем перебор соседей
        } // завершаем условие посещения текущей вершины
    } // завершаем цикл DFS

    return result; // возвращаем результат обхода
} // завершаем метод dfs

vector<string> Graph::findPath(const string& startVertex, const string& endVertex) { // реализуем поиск пути между вершинами
    vector<string> path; // создаём список для хранения найденного пути
    map<string, bool> visited; // создаём карту посещённых вершин
    map<string, string> previous; // создаём карту для хранения предыдущих вершин
    queue<string> q; // создаём очередь для поиска пути с помощью BFS

    if (!hasVertex(startVertex) || !hasVertex(endVertex)) { // проверяем, существуют ли начальная и конечная вершины
        return path; // если одной из вершин нет, возвращаем пустой путь
    } // завершаем условие

    visited[startVertex] = true; // отмечаем стартовую вершину как посещённую
    q.push(startVertex); // добавляем стартовую вершину в очередь

    while (!q.empty()) { // выполняем цикл, пока очередь не пустая
        string current = q.front(); // берём первую вершину из очереди
        q.pop(); // удаляем эту вершину из очереди

        if (current == endVertex) { // проверяем, достигнута ли конечная вершина
            break; // если конечная вершина найдена, прекращаем поиск
        } // завершаем условие

        for (const string& neighbor : adjacencyList[current]) { // перебираем соседей текущей вершины
            if (!visited[neighbor]) { // проверяем, был ли сосед посещён
                visited[neighbor] = true; // отмечаем соседа как посещённого
                previous[neighbor] = current; // запоминаем, из какой вершины пришли к соседу
                q.push(neighbor); // добавляем соседа в очередь
            } // завершаем условие
        } // завершаем перебор соседей
    } // завершаем цикл поиска

    if (!visited[endVertex]) { // проверяем, была ли достигнута конечная вершина
        return path; // если путь не найден, возвращаем пустой список
    } // завершаем условие

    string current = endVertex; // начинаем восстановление пути с конечной вершины

    while (current != startVertex) { // идём назад, пока не дойдём до стартовой вершины
        path.push_back(current); // добавляем текущую вершину в путь
        current = previous[current]; // переходим к предыдущей вершине
    } // завершаем восстановление пути

    path.push_back(startVertex); // добавляем стартовую вершину в путь
    reverse(path.begin(), path.end()); // разворачиваем путь в правильный порядок

    return path; // возвращаем найденный путь
} // завершаем метод findPath
