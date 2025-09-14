#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSum(vector<int> &, int);

int main() {
    vector<int> nums {3, 2, 4};
    int target = 6;

    vector<int> sum_idx = twoSum(nums, target);

    return 0;
}


std::vector<int> twoSum(std::vector<int> & nums, int target) {
    unordered_map<int, int> prev_nums;

    for (int num_count = 0; num_count < nums.size(); num_count++) {
        int required = target - nums[num_count];

        if (prev_nums.find(required) != prev_nums.end()) {
            return {prev_nums[required], num_count};
        }

        prev_nums[nums[num_count]] = num_count;    
    }

    return vector<int> {-1, -1};
}