#ifndef A_H
#define A_H

#include <iostream>
#include <string>
#include <Intersections.h>
#include <Graph.h>
#include <FloydWarshall.h>
#include <Permutation.h>
#include <vector>
#include <sstream>

void test(
    int n,
    int m, 
    std::vector<std::string> intrs, 
    std::vector<std::string> info, 
    int startingIntersection,
    int destCountToVisit,
    std::vector<std::string> destsToVisit
) {
    Intersections intersections(n);
    Graph graph(n);

    for (int i = 0; i < n; i++) {
        intersections.addIntersection(intrs[i], i);
    }

    std::string tmp;
    std::stringstream stream;
    std::vector<std::string> vec;
    for (int i = 0; i < m; i++) {
        tmp = info[i];
        std::stringstream stream(tmp);
        vec.clear();

        std::string s;
        while (getline(stream, s, ' ')) {
            vec.push_back(s);
        }
        graph.addEdge(intersections.getIntersectionIndex(vec[0]), intersections.getIntersectionIndex(vec[1]), std::stoi(vec[2]));
    }

    FloydWarshall floydWarshall(graph);
    Permutation permutation;

    std::vector<int> destIndex;
    for (auto d: destsToVisit) {

        destIndex.push_back(intersections.getIntersectionIndex(d));
    }
    
    std::vector<int> bestPermutation = permutation.findBestPermutation(destIndex, floydWarshall, startingIntersection);

    std::cout << "Best order of destinations" << std::endl;
    for (int dest: bestPermutation) {
        std::cout << intersections.getIntersectionName(dest) << " ";
    }
    std::cout << std::endl;

    int currentIntersection = startingIntersection;
    int distanceSum = 0;
    std::cout << "Length of trips" << std::endl;
    for (int dest: bestPermutation) {
        int distance = floydWarshall.getShortestDistance(currentIntersection, dest);
        std::string startIntersection = intersections.getIntersectionName(currentIntersection);
        std::string endIntersection = intersections.getIntersectionName(dest);
        std::cout << "From " << startIntersection << " to " << endIntersection << " = " << distance << std::endl;
        distanceSum += distance;
        currentIntersection = dest;
    }
    int distance = floydWarshall.getShortestDistance(currentIntersection, startingIntersection);
    std::string startIntersection = intersections.getIntersectionName(currentIntersection);
    std::string endIntersection = intersections.getIntersectionName(startingIntersection);
    std::cout << "From " << startIntersection << " to " << endIntersection << " = " << distance << std::endl;
    distanceSum += distance;
    std::cout << "Length of travel = " << distanceSum;
}

void dynamicTest() {
    int n, m;
    std::cout << "Enter number of intersections(n) and roads(m)" << std::endl;
    std::cin >> n >> m;

    Intersections names(n);
    Graph graph(n);

    for (int i = 0; i < n; i++) {
        std::cout << "Enter " << i + 1 <<  " intersection name" << std::endl;
        std::string name;
        std::cin >> name;
        names.addIntersection(name, i);
    }

    std::cout << "Enter description between roads" << std::endl;    
    for (int i = 0; i < m; i++) {
        std::string start, end;
        int lenght;

        std::cin >> start >> end >> lenght;

        int startIndex = names.getIntersectionIndex(start);
        int endIndex = names.getIntersectionIndex(end);

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
        destsToVisit[i] = names.getIntersectionIndex(destName); 
    }

    FloydWarshall floydWarshall(graph);
    Permutation permutation;

    std::vector<int> bestPermutation = permutation.findBestPermutation(destsToVisit, floydWarshall, startingIntersection);

    std::cout << "Best order of destinations" << std::endl;
    for (int dest: bestPermutation) {
        std::cout << names.getIntersectionName(dest) << " ";
    }
    std::cout << std::endl;

    int currentIntersection = startingIntersection;
    int distanceSum = 0;
    std::cout << "Length of trips" << std::endl;
    for (int dest: bestPermutation) {
        int distance = floydWarshall.getShortestDistance(currentIntersection, dest);
        std::cout << "From " << names.getIntersectionName(currentIntersection) << " to " << names.getIntersectionName(dest) << " = " << distance << std::endl;
        distanceSum += distance;
        currentIntersection = dest;
    }
    int distance = floydWarshall.getShortestDistance(currentIntersection, startingIntersection);
    std::cout << "From " << names.getIntersectionName(currentIntersection) << " to " << names.getIntersectionName(startingIntersection) << " = " << distance << std::endl;
    distanceSum += distance;
    std::cout << "Length of travel = " << distanceSum;
}

#endif
