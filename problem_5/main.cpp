#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string longestPalindrome(string);
void expand_around_center(const string &p_s, int p_left, int p_right, int &p_start, int &p_max_len);

int main() {
    string str = "babad";
    string largest_palindrome = longestPalindrome(str);

    cout << "Palindrome: " << largest_palindrome; 

    return 0;
}


string longestPalindrome(string s) {
    int m_start = 0, m_max_len = 1;

    for (int m_char_count = 0; m_char_count < s.size(); m_char_count++) {
        expand_around_center(s, m_char_count, m_char_count, m_start, m_max_len);
        expand_around_center(s, m_char_count, m_char_count + 1, m_start, m_max_len);
    }

    return s.substr(m_start, m_max_len);
}



void expand_around_center(const string &p_s, int p_left, int p_right, int &p_start, int &p_max_len) {
    int m_str_size = p_s.size();

    while (p_left >= 0 && p_right < m_str_size && p_s[p_left] == p_s[p_right])
    {
        int m_curr_palindrome_len = p_right - p_left + 1;

        if (p_max_len < m_curr_palindrome_len) {
            p_start = p_left;
            p_max_len = m_curr_palindrome_len;
        }

        p_left--;
        p_right++;
    }
}