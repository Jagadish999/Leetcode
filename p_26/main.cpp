#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int uniqueCount = 0;
        std::vector<int> uniqueNums;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == nums[i + 1]) continue;

            uniqueNums.push_back(nums[i]);
            uniqueCount++;
        }

        if (uniqueNums[uniqueNums.size() - 1] != nums[nums.size() - 1]) {
            uniqueNums.push_back(nums[nums.size() - 1]);
            uniqueCount++;
        }

        nums = uniqueNums;
        return uniqueCount;
    }
};


int main() {



    return 0;
}