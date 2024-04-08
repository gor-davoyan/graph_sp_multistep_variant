#include <iostream>
#include <string>
#include <Intersections.h>
#include <Graph.h>
#include <FloydWarshall.h>
#include <Permutation.h>
#include <vector>
#include <Test.h>

void test1() {
    int n = 5, m = 10;
    std::vector<std::string> intrs = {"A", "B", "C", "D", "E"};
    std::vector<std::string> info = {"A B 4", "A D 5", "B C 1", "B E 6", "C D 3", "C A 2", "D C 1", "D E 2", "E D 4", "E A 1"};
    std::vector<std::string> destsToVisit = {"A", "D"};
    int startingIntersection = 1;
    int destCOuntToVisit = 2;
    test(
        n, m,
        intrs,
        info,
        startingIntersection,
        destCOuntToVisit,
        destsToVisit
    );
}

void test2() {
    int n = 5, m = 10;
    std::vector<std::string> intrs = {"A", "B", "C", "D"};
    std::vector<std::string> info = {"A B 3", "B C 5", "C D 7", "D A 1"};
    std::vector<std::string> destsToVisit = {"D", "B"};
    int startingIntersection = 0;
    int destCOuntToVisit = 2;
    test(
        n, m,
        intrs,
        info,
        startingIntersection,
        destCOuntToVisit,
        destsToVisit
    );
}

int main() {

    // test1();
    test2();

    // dynamicTest();
}
