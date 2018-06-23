#include <iostream>
#include <vector>
#include <utility>

typedef std::pair<std::vector<int>, long long int> invReturn;

invReturn countSplitInv(std::vector<int>& l, std::vector<int>& r);

invReturn countInv(std::vector<int>& a);

long long int bruteCount(const std::vector<int>& a);
