#ifndef FLOYD_WARSHALL
#define FLOYD_WARSHALL

#include <vector>
#include <algorithm>
#include <Graph.h>
#include <iostream>

class FloydWarshall {
private:
    std::vector<std::vector<int>> shortDist;
public:
    FloydWarshall(Graph& graph) {
        int n = graph.getDistances().size();
        shortDist = graph.getDistances();
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    shortDist[i][j] = std::min(shortDist[i][j], shortDist[i][k] + shortDist[k][j]);
                }
            }
        }
    }

    int getShortestDistance(int start, int end) {
        return shortDist[start][end];
    }
};


#endif // FLOYD_WARSHALL
