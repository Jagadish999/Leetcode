#include "Solution.h"

#include <vector>
#include <iostream>

void print_two_sum_idxs(std::vector <int> &);

int main() {
    Solution soln;

    std::vector<int> test_case_vector_1 = {2,7,11,15};
    int test_case_target_1 = 9;

    std::vector<int> test_case_vector_2 = {3, 2, 4};
    int test_case_target_2 = 6;

    std::vector<int> test_case_vector_3 = {3, 3};
    int test_case_target_3 = 6;

    std::vector<int> result_1 = soln.twoSum(test_case_vector_1, test_case_target_1);
    std::vector<int> result_2 = soln.twoSum(test_case_vector_2, test_case_target_2);
    std::vector<int> result_3 = soln.twoSum(test_case_vector_3, test_case_target_3);

    print_two_sum_idxs(result_1);
    print_two_sum_idxs(result_2);
    print_two_sum_idxs(result_3);

    return 0;
}

void print_two_sum_idxs(std::vector <int> & nums) {
    std::cout << "Number is: " << nums[0] << " and " << nums[1] << std::endl;
}