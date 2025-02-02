#include <iostream>
#include <vector>

#include "Solution.h"

int main() {
    Solution soln;

    std::vector<int> num1 = {1, 2};
    std::vector<int> num2 = {3, 4};

    double median = soln.findMedianSortedArrays(num1, num2);

    std::cout << "Median is: " << median << std::endl;

    return 0;
}