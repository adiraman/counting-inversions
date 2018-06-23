#include "countInv.h"
#include <ctime>
#include <iostream>

invReturn countSplitInv(std::vector<int>& l, std::vector<int>& r)
{
    std::vector<int> m;
    // declare indices to the left and right sub arrays
    int i{ 0 }, j{ 0 };
    int l_sz = l.size();
    int r_sz = r.size();
    int counter = 0;

    while (i < l_sz && j < r_sz) {
        if (l[i] > r[j]) {
            m.push_back(r[j]);
            counter += l.size() - i;
            ++j;
        } else {
            m.push_back(l[i]);
            ++i;
        }
    }

    while (i < l_sz && j == r_sz) {
        m.push_back(l[i]);
        ++i;
    }

    while (i == l_sz && j < r_sz) {
        m.push_back(r[j]);
        ++j;
    }

    return std::make_pair(m, counter);
}

invReturn countInv(std::vector<int>& a)
{
    // Check for base case to stop the recursion
    int n = a.size();
    if (n == 1) {
        return std::make_pair(a, 0);
    }

    // Partition to Left and Right halves
    std::vector<int> l, r;
    for (int i = 0; i < n; ++i) {
        if (i < n / 2)
            l.push_back(a[i]);
        else
            r.push_back(a[i]);
    }

    invReturn x = countInv(l);                     // count left inversions
    invReturn y = countInv(r);                     // count right inversions
    invReturn z = countSplitInv(x.first, y.first); // count split inversions

    // Merge the left and right halves procedurally and return
    return std::make_pair(z.first, (x.second + y.second + z.second));
}

long long int bruteCount(const std::vector<int>& a)
{

    long long int count = 0;
    int sz = a.size();
    for (int i = 0; i < sz - 1; ++i) {
        for (int j = i + 1; j < sz; ++j) {
            if (a[i] > a[j])
                ++count;
        }
    }

    return count;
}
