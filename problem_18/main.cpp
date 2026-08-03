#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target);

int main() {
    vector<int> nums = {2,2,2,2,2};



    return 0;
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    if (nums.size() < 4) {
        return res;
    }
    
    sort(nums.begin(), nums.end());


    for (int first_ptr = 0; first_ptr < nums.size() - 3; first_ptr++) {
        if (first_ptr > 0 && nums[first_ptr] == nums[first_ptr - 1]) continue;

        for (int sec_ptr = first_ptr + 1; sec_ptr < nums.size() - 2; sec_ptr++) {
            if (sec_ptr > first_ptr + 1 && nums[sec_ptr] == nums[sec_ptr - 1]) continue;

            int third_ptr = sec_ptr + 1;
            int last_ptr = nums.size() - 1;

            while (third_ptr < last_ptr)
            {
                long long m_total_sum = (long long)(nums[first_ptr] + (long long)nums[sec_ptr] + (long long)nums[third_ptr] + (long long)nums[last_ptr]);
                
                if (m_total_sum == target) {
                    vector<int> m_target {nums[first_ptr], nums[sec_ptr], nums[third_ptr], nums[last_ptr]};
                    res.push_back(m_target);
                    
                    while (third_ptr < last_ptr && nums[third_ptr] == nums[third_ptr + 1]) third_ptr++;
                    while (third_ptr < last_ptr && nums[last_ptr] == nums[last_ptr - 1]) last_ptr--;
                    
                    third_ptr++;
                    last_ptr--;
                }
                else if (m_total_sum < target)
                {
                    third_ptr++;
                }
                else {
                    last_ptr--;
                }
            }
        }
    }

    return res;
}