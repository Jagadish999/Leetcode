/*
Problem Number 11
Container With Most Water
*/

#include <vector>
#include <iostream>

using namespace std;


int maxArea(vector<int> &);

int main() {

    vector<int> heights {1, 8, 6, 2, 5, 4, 8, 3, 7};

    int max_area = maxArea(heights);

    cout << "Max Area is: " << max_area << endl;

    return 0;
}


int maxArea(vector<int> & height) {
    int m_left_pointer = 0;
    int m_right_pointer = height.size() - 1;

    int m_max_area = 0;

    while (m_left_pointer < m_right_pointer) {
        int m_min_height = min(height[m_left_pointer], height[m_right_pointer]);
        int m_surface_len = m_right_pointer - m_left_pointer;

        m_max_area = max(m_max_area, m_min_height * m_surface_len);

        if (height[m_right_pointer] < height[m_left_pointer]) {
            m_right_pointer--;
        }
        else {
            m_left_pointer++;
        }
    }

    return m_max_area;
}

int maxArea_brute_force(vector<int> & height) {
    int m_max_area = 0;

    for (int m_start = 0; m_start < height.size() - 1; m_start++) {
        for (int m_end = m_start + 1; m_end < height.size(); m_end++) {
            int m_surface_len = m_end - m_start;
            int m_min_height = min(height[m_start], height[m_end]);

            int m_surface_area = m_min_height * m_surface_len;

            m_max_area = max(m_surface_area, m_max_area);
        }
    }

    return m_max_area;
}