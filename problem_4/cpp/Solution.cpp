#include "Solution.h"

double Solution::findMedianSortedArrays(std::vector<int> & num1, std::vector <int> & num2) {
    std::vector<int> merged_vector = merge_two_arrays(num1, num2);
    sort_given_array(merged_vector);

    if (merged_vector.size() == 0) {
        return 0;
    }
    else if(merged_vector.size() == 1) {
        return merged_vector[0];
    }

    double median;

    if (merged_vector.size() % 2 == 0) {
        int first_mid_num = (merged_vector.size() / 2) - 1;
        int second_mid_num = merged_vector.size() / 2;

        median = (merged_vector[first_mid_num] + merged_vector[second_mid_num]) / 2.0;
    }
    else {
        median = merged_vector[merged_vector.size() / 2];
    }

    return median;
}

std::vector<int> Solution::merge_two_arrays(std::vector<int>& num1, std::vector <int> & num2) {
    std::vector<int> joined_vector = {};
    for (int i = 0; i < num1.size(); i++) {
        joined_vector.push_back(num1[i]);
    }

    for (int i = 0; i < num2.size(); i++){
        joined_vector.push_back(num2[i]);
    }

    return joined_vector;
}

void Solution::sort_given_array(std::vector<int>& num1) {
    for (int i = 0; i < num1.size() - 1; i++) {
        for (int j = i + 1; j < num1.size(); j++) {
            if (num1[i] > num1[j]) {
                int temp = num1[i];

                num1[i] = num1[j];
                num1[j] = temp;
            }
        }
    }

}