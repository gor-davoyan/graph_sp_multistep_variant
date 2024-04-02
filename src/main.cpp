#include <iostream>
#include <string>
#include <Intersections.h>
#include <Graph.h>
#include <FloydWarshall.h>
#include <Permutation.h>
#include <vector>

int main() {
    int n, m;
    std::cout << "Enter number of intersections(n) and roads(m)" << std::endl;
    std::cin >> n >> m;

    Intersections names(n);
    Graph graph(n);

    for (int i = 0; i < n; i++) {
        std::cout << "Enter " << i + 1 <<  " intersection name" << std::endl;
        std::string name;
        std::cin >> name;
        names.addName(name, i);
    }

    std::cout << "Enter description between roads" << std::endl;    
    for (int i = 0; i < m; i++) {
        std::string start, end;
        int lenght;

        std::cin >> start >> end >> lenght;

        int startIndex = names.getIndex(start);
        int endIndex = names.getIndex(end);

        graph.addEdge(startIndex, endIndex, lenght);
    }

    int startingIntersection;
    std::cout << "Enter starting intersection index" << std::endl;
    std::cin >> startingIntersection;

    int destCountToVisit;
    std::cout << "Enter count of destinations to visit" << std::endl;
    std::cin >> destCountToVisit;

    std::vector<int> destsToVisit(destCountToVisit);
    for (int i = 0; i < destCountToVisit; i++) {
        std::cout << "Enter " << i <<  " destination name to visit" << std::endl;
        std::string destName;
        std::cin >> destName;
        destsToVisit[i] = names.getIndex(destName); 
    }

    FloydWarshall floydWarshall(graph);
    Permutation permutation;

    std::vector<int> bestPermutation = permutation.findBestPermutation(destsToVisit, floydWarshall, startingIntersection);

    std::cout << "Best order of destinations" << std::endl;
    for (int dest: bestPermutation) {
        std::cout << names.getName(dest) << " ";
    }
    std::cout << std::endl;

    int currentIntersection = startingIntersection;
    int distanceSum = 0;
    std::cout << "Length of trips" << std::endl;
    for (int dest: bestPermutation) {
        int distance = floydWarshall.getShortestDistance(currentIntersection, dest);
        std::cout << "From " << names.getName(currentIntersection) << " to " << names.getName(dest) << " = " << distance << std::endl;
        distanceSum += distance;
        currentIntersection = dest;
    }
    int distance = floydWarshall.getShortestDistance(currentIntersection, startingIntersection);
    std::cout << "From " << names.getName(currentIntersection) << " to " << names.getName(startingIntersection) << " = " << distance << std::endl;
    distanceSum += distance;
    std::cout << "Length of travel = " << distanceSum;
}
