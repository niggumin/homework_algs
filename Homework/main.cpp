// 1
// Необходимо написать несколько реализаций интерфейса:
//  - ListGraph, хранящий граф в виде массива списков смежности,
//  - MatrixGraph, хранящий граф в виде матрицы смежности,
//  - SetGraph, хранящий граф в виде массива хэш-таблиц/сбалансированных деревьев поиска,
//  - ArcGraph, хранящий граф в виде одного массива пар {from, to}.

// Также необходимо реализовать конструктор, принимающий const IGraph&.
// Такой конструктор должен скопировать переданный граф в создаваемый объект.
// Для каждого класса создавайте отдельные h и cpp файлы.
// Число вершин графа задается в конструкторе каждой реализации.



#include <iostream>
#include <vector>
#include <set>
#include <cassert>
#include <functional>
#include <queue>
#include <deque>
#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"
#include "ArcGraph.h"
#include "SetGraph.h"



int main(int argc, const char * argv[]) {
    ListGraph listGraph(7);
    listGraph.AddEdge(0, 1);
    listGraph.AddEdge(0, 5);
    listGraph.AddEdge(1, 2);
    listGraph.AddEdge(1, 3);
    listGraph.AddEdge(1, 5);
    listGraph.AddEdge(1, 6);
    listGraph.AddEdge(3, 2);
    listGraph.AddEdge(3, 4);
    listGraph.AddEdge(3, 6);
    listGraph.AddEdge(5, 4);
    listGraph.AddEdge(5, 6);
    listGraph.AddEdge(6, 4);
    
    mainBFS(listGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    mainDFS(listGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    for (int vertex: topologicalSort(listGraph))
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl << std::endl;
    
    
    
    MatrixGraph matrixGraph(listGraph);
    
    mainBFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    mainDFS(matrixGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    for (int vertex: topologicalSort(matrixGraph))
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl << std::endl;
    
    
    
    ArcGraph arcGraph(matrixGraph);
    
    mainBFS(arcGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    mainDFS(arcGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    for (int vertex: topologicalSort(arcGraph))
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl << std::endl;
    
    
    
    SetGraph setGraph(arcGraph);
    
    mainBFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    mainDFS(setGraph, [](int vertex){ std::cout << vertex << " "; });
    std::cout << std::endl;
    
    for (int vertex: topologicalSort(setGraph))
    {
        std::cout << vertex << " ";
    }
    std::cout << std::endl << std::endl;
    
    std::cout << "listGraph size: " << listGraph.VerticesCount() << std::endl;
    std::cout << "matrixGraph size: " << matrixGraph.VerticesCount() << std::endl;
    std::cout << "arcGraph size: " << arcGraph.VerticesCount() << std::endl;
    std::cout << "setGraph size: " << setGraph.VerticesCount() << std::endl;
    // Нужно продемонстрировать работу конструктора копирования, проинициализировав
    // графы разных классов друг от друга. Далее, показать, что вершины и ребра
    // успешно скопированы: число вершин осталось прежним, произвести BFS и DFS.
    // MatrixGraph matrixGraph(listGraph);
    // ArcGraph arcGraph(matrixGraph);
    // SetGraph setGraph(arcGraph);
    return 0;
}
