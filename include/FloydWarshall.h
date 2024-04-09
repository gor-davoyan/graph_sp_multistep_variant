#ifndef FLOYD_WARSHALL
#define FLOYD_WARSHALL

#include <vector>
#include <algorithm>
#include <Graph.h>
#include <iostream>

class FloydWarshall {
private:
    std::vector<std::vector<int>> shortDist;
    std::vector<std::vector<int>> mid;

    void initMidVector(int n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (shortDist[i][j] != Graph::MAX_VALUE && i != j) {
                    mid[i][j] = j;
                }
            }
        }
    }
public:
    FloydWarshall(Graph& graph) {
        int n = graph.getDistances().size();
        shortDist = graph.getDistances();

        mid.resize(n, std::vector<int>(n, -1));
        initMidVector(n);


        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (shortDist[i][k] < Graph::MAX_VALUE && shortDist[k][j] < Graph::MAX_VALUE &&
                    shortDist[i][j] > shortDist[i][k] + shortDist[k][j]){
                        shortDist[i][j] = shortDist[i][k] + shortDist[k][j];
                        mid[i][j] = mid[i][k];
                    }
                    
                    // shortDist[i][j] = std::min(shortDist[i][j], shortDist[i][k] + shortDist[k][j]);
                }
            }
        }
    }

    int getShortestDistance(int start, int end) {
        return shortDist[start][end];
    }

    std::vector<int> getMidElements(int start, int end) {
        if (mid[start][end] == -1) {
            return {};
        }

        std::vector<int> result;
        result.push_back(start);

        while (start != end) {
            start = mid[start][end];
            result.push_back(start);
        }
        
        return result;
    }
};


#endif // FLOYD_WARSHALL
