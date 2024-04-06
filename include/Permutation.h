#ifndef PERMUTATION
#define PERMUTATION

#include <vector>
#include <FloydWarshall.h>

class Permutation {
private:
    std::vector<std::vector<int>> getPermutations(std::vector<int>& perm) {
    std::vector<std::vector<int>> permutations;
    std::sort(perm.begin(), perm.end());
    do {
        permutations.push_back(perm);
    } while (std::next_permutation(perm.begin(), perm.end()));
    return permutations;
}

public:

    std::vector<int> findBestPermutation(
        std::vector<int>& perm,
        FloydWarshall& floydWarshall,
        int startingIntersection
    ) {
        std::vector<std::vector<int>> permutations = getPermutations(perm);

        int minDistance = INT_MAX;
        std::vector<int> bestPermutation;
        for (auto& perm: permutations) {
            int distance = 0;
            int currentIntersecttion = startingIntersection;

            for (int dest: perm) {
                distance += floydWarshall.getShortestDistance(currentIntersecttion, dest);
                currentIntersecttion = dest;
            }
            std::cout << std::endl;
            distance += floydWarshall.getShortestDistance(currentIntersecttion, startingIntersection);

            if (distance < minDistance) {
                minDistance = distance;
                bestPermutation = perm;
            }
        }
    
        return bestPermutation;
    }
};

#endif // PERMUTATION
