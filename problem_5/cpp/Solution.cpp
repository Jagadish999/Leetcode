#include <string>
#include "Solution.h"
#include <iostream>


std::string Solution::longestPalindrome(std::string s) {
    std::string m_longest_palindrome = "";
    int m_longest_size = 0;

    for (int i = 0; i < s.size(); i++) {
        int m_left_pointer = i;
        int m_right_pointer = i;

        while (m_left_pointer >= 0 && m_right_pointer < s.size() && s[m_left_pointer] == s[m_right_pointer]) {
            
            int m_sub_str_size = m_right_pointer - m_left_pointer + 1;

            if (m_sub_str_size > m_longest_size) {
                m_longest_palindrome = s.substr(m_left_pointer, m_sub_str_size);
                m_longest_size = m_sub_str_size;
            }

            m_left_pointer -= 1;
            m_right_pointer += 1;
        }
        m_left_pointer = i;
        m_right_pointer = i + 1;

        while (m_left_pointer >= 0 && m_right_pointer < s.size() && s[m_left_pointer] == s[m_right_pointer]) {
            
            int m_sub_str_size = m_right_pointer - m_left_pointer + 1;

            if (m_sub_str_size > m_longest_size) {
                m_longest_palindrome = s.substr(m_left_pointer, m_sub_str_size);
                m_longest_size = m_sub_str_size;
            }

            m_left_pointer -= 1;
            m_right_pointer += 1;
        }
    }

    return m_longest_palindrome;
}
