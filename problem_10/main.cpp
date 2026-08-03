/*
Problem 10: Regular Experssion Matching

Here,
'.' Matches any single charachers
'*' Matches zero or more of the preceding element.


Example 1:
s = "aa", p = "a",
output = false

Example 2:
s = "aa", p = "a*"
output = true

Example 3:
s = "ab", p = ".*"
output = true

Example 4:
s = "aab", p = "c*a*b*"
output = true
*/

#include <string>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

bool isMatch(string, string);

int main() {

    string m_s1 = "aa";
    string m_p1 = "a";

    // cout << "String is: " << m_s1 << endl;
    // cout << "Pattern is: " << m_p1 << endl << endl;

    // bool m_is_matcing_1 = isMatch(m_s1, m_p1);
    // cout << "Is Match: " << m_is_matcing_1 << endl;

    string m_s2 = "aa";
    string m_p2 = "a*";

    cout << "String is: " << m_s2 << endl;
    cout << "Pattern is: " << m_p2 << endl << endl;

    bool m_is_matching_2 = isMatch(m_s2, m_p2);
    cout << "Is Match: " << m_is_matching_2 << endl;

    string m_s3 = "aab";
    string m_p3 = "c*a*b";

    // cout << "String is: " << m_s3 << endl;
    // cout << "Pattern is: " << m_p3 << endl << endl;

    // bool m_is_matching_3 = isMatch(m_s3, m_p3);
    // cout << "Is Match: " << m_is_matching_3 << endl;


    string m_s4 = "ab";
    string m_p4 = ".*c";

    // cout << "String is: " << m_s4 << endl;
    // cout << "Pattern is: " << m_p4 << endl << endl;

    // bool m_is_matching_4 = isMatch(m_s4, m_p4);
    // cout << "Is Match: " << m_is_matching_4 << endl;

    return 0;
}


bool isMatch(string s, string p) {
    int m_str_len = s.size();
    int m_ptn_len = p.size();

    vector<vector<int>> memo(m_str_len + 1, vector(m_ptn_len + 1, -1));

    function <bool(int, int)> match_str_and_ptn = [&](int p_str_idx, int p_ptn_idx) -> bool {
        // First Univesal condition of bot index is overflowing then it is true
        if (p_str_idx >= m_str_len && p_ptn_idx >= m_ptn_len){
            return true;
        } 
            
        // Pattern Index is overflowing
        if (p_ptn_idx >= m_ptn_len){
            return false;
        }

        if (memo[p_str_idx][p_ptn_idx] != -1) return memo[p_str_idx][p_ptn_idx] == 1;
       
        // Check if pattern matches or not, p_str should be in bound
        bool is_current_char_matching = p_str_idx < m_str_len && (s[p_str_idx] == p[p_ptn_idx] || p[p_ptn_idx] == '.');

        bool m_result = false;
        // If Next char in pattern has star, need to explore two possiblity
        // It can be either empty or repeate preceding character infinite time
        if (p[p_ptn_idx + 1] == '*') {
            m_result = (is_current_char_matching && match_str_and_ptn(p_str_idx + 1, p_ptn_idx)) || match_str_and_ptn(p_str_idx, p_ptn_idx + 2);
        }
        else if (is_current_char_matching) {
            m_result = match_str_and_ptn(p_str_idx + 1, p_ptn_idx + 1);
        }

        memo[p_str_idx][p_ptn_idx] = m_result ? 1 : 0;

        return m_result;
    };

    return match_str_and_ptn(0, 0);
}