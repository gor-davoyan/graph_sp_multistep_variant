#ifndef GRAPH
#define GRAPH

#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> distances;
public:
    const static int MAX_VALUE;
    Graph() {}
    Graph(int n): distances(n, std::vector<int>(n, MAX_VALUE)) {
        for (int i = 0; i < n; ++i) {
            distances[i][i] = 0;
        }
    };

    void addEdge(int start, int end, int length) {
        distances[start][end] = length;
    }

    std::vector<std::vector<int>> getDistances() {
        return distances;
    }
};

const int Graph::MAX_VALUE = 100000;

#endif // GRAPH