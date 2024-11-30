#include "Solution.h"

#include <unordered_map>

std::vector<int> Solution::twoSum(std::vector<int> & nums, int target) {
    std::vector<int> nums_list;
    std::unordered_map<int, int> maps;

    for (int count = 0; count < nums.size(); count++) {
        int m_current_num = nums[count];
        int m_extra_num = target - m_current_num;

        if (maps.find(m_extra_num) != maps.end()) {
            nums_list.push_back(count);
            nums_list.push_back(maps[m_extra_num]);

            break;
        }
        maps[m_current_num] = count;
    }

    return nums_list;
};