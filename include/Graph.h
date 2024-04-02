#ifndef GRAPH
#define GRAPH

#include <vector>

class Graph {
private:
    std::vector<std::vector<int>> distances;
public:
    Graph() {}
    Graph(int n): distances(n, std::vector<int>(n, -1)) {
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


#endif // GRAPH