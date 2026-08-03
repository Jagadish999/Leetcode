#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &, int);

int main() {


    return 0;
}

int threeSumClosest(vector<int> & nums, int target) {
    sort(nums.begin(), nums.end());

    int m_closest_sum = nums[0] + nums[1] + nums[2];

    for (int m_start = 0; m_start < nums.size() - 2; m_start++) {
        // Skip if previous starting number was same to current one
        if (m_start > 0 && nums[m_start] == nums[m_start - 1]) continue;
    
        int m_left_ptr = m_start + 1;
        int m_right_ptr = nums.size() - 1;
        
        while (m_left_ptr < m_right_ptr)
        {
            int m_current_sum = nums[m_start] + nums[m_left_ptr] + nums[m_right_ptr];

            if(abs(target - m_current_sum) < abs(target - m_closest_sum)) {
                m_closest_sum = m_current_sum;
            }

            if (m_current_sum < target) {
                m_left_ptr++;
            }
            else if (m_current_sum > target)
            {
                m_right_ptr--;
            }
            else{
                return m_current_sum;
            }
        }
    }

    return m_closest_sum;
}