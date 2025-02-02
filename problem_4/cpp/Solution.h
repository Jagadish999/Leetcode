#ifndef SOLUTION_H
#define SOLUTION_H

#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int> & num1, std::vector <int> & num2);
    std::vector<int> merge_two_arrays(std::vector<int>& num1, std::vector <int> & num2);
    void sort_given_array(std::vector<int>& num1);
};

#endif