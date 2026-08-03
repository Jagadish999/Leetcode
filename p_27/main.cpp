#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        std::vector<int> filteredNums;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                filteredNums.push_back(nums[i]);
            }
        }

        nums = filteredNums;
        return filteredNums.size();
    }
};


int main() {



    return 0;
}