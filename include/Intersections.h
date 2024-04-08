#ifndef INTERSECTIONS
#define INTERSECTIONS

#include <unordered_map>
#include <string>

class Intersections {
private:
    std::unordered_map<std::string, int> nameToIndex;
    std::unordered_map<int, std::string> indexToName;

public:
    Intersections(int n): nameToIndex(n), indexToName(n) {}

    void addIntersection(const std::string& name, int index) {
        nameToIndex[name] = index;
        indexToName[index] = name;
    }

    int getIntersectionIndex(const std::string& name) {
        return nameToIndex[name];
    }

    std::string getIntersectionName(int index) {
        return indexToName[index];
    }
};

#endif // INTERSECTIONS