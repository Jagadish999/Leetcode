#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums);

int main() {


    return 0;
}


vector<vector<int>> threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
   
    vector<vector<int>> m_three_sum_nums;

    for (int m_first_idx = 0; m_first_idx < nums.size() - 2; m_first_idx++) {
        if (m_first_idx > 0 && nums[m_first_idx] == nums[m_first_idx - 1]) continue;

        int m_mid_pointer = m_first_idx + 1;
        int m_last_pointer = nums.size() - 1;

        while (m_mid_pointer < m_last_pointer) {
            int m_sum = nums[m_first_idx] + nums[m_mid_pointer] + nums[m_last_pointer];

            if (m_sum > 0) {
                m_last_pointer--;
            }
            else if (m_sum < 0)
            {
                m_mid_pointer++;
            }
            else
            {
                vector<int> m_three_sums {nums[m_first_idx], nums[m_mid_pointer], nums[m_last_pointer]};
                m_three_sum_nums.push_back(m_three_sums);

                while (m_mid_pointer < m_last_pointer && nums[m_mid_pointer] == nums[m_mid_pointer + 1]) m_mid_pointer++;
                while (m_last_pointer > m_mid_pointer && nums[m_last_pointer] == nums[m_last_pointer - 1]) m_last_pointer--;
                
                m_mid_pointer++;
                m_last_pointer--;
            }
        }
    }
  
    return m_three_sum_nums;
}