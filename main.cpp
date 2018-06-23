#include "countInv.h"
#include <cstdlib>
#include <ctime>

void printVec(const std::vector<int>& a)
{
    for (auto i : a) {
        std::cout << i << ", ";
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << "<vector size> <low val> <high val>" << std::endl;
        return 0;
    }

    int n = atoi(argv[1]);
    std::vector<int> a(n);

    srand(time(nullptr));

    int Lo = atoi(argv[2]);
    int Hi = atoi(argv[3]);

    for (int i = 0; i < n; ++i) {
        a[i] = Lo + (rand() / (RAND_MAX / (Hi - Lo)));
    }

    std::cout << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "         Input array             " << std::endl;
    printVec(a);
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "                         O(n.log(n)) method       " << std::endl;
    std::cout << std::endl;
    std::cout << "       Number of inversions :     ";

    std::clock_t start;
    start = std::clock();

    std::cout << countInv(a).second << std::endl;

    std::cout << "                   CPU Time :     " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << std::endl;
    std::cout << "                         Brute force method       " << std::endl;
    std::cout << std::endl;
    std::cout << "       Number of inversions :     ";

    start = std::clock();
    std::cout << bruteCount(a) << std::endl;

    std::cout << "                   CPU Time :     " << (std::clock() - start) / (double)(CLOCKS_PER_SEC / 1000) << " ms" << std::endl;

    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << std::endl;

    return 0;
}
