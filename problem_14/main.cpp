#include <iostream>
#include <vector>

using namespace std;

int main() {


    return 0;
}


string longestCommonPrefix(vector<string>& strs) {
    string m_common_prefix = "";
    string m_first_str = strs[0];
    
    for (int m_ch_idx = 0; m_ch_idx < m_first_str.size(); m_ch_idx++) {
        char m_first_str_current_ch = m_first_str[m_ch_idx];

        for (string str: strs) {
            if (str.size() - 1 < m_ch_idx) return m_common_prefix;

            if (str[m_ch_idx] != m_first_str_current_ch) return m_common_prefix;            
        }

        m_common_prefix += m_first_str_current_ch;
    }

    return m_common_prefix;
}