#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatch(string, string);


int main() {
    string s1 = "aa";
    string p1 = "a";

    cout << "String: " << s1 << " Pattern: " << p1 << endl;
    cout << "Is Match: " << isMatch(s1, p1) << endl;

    string s2 = "aa";
    string p2 = "a*";

    cout << "String: " << s2 << " Pattern: " << p2 << endl;
    cout << "Is Match: " << isMatch(s2, p2) << endl;

    string s3 = "ab";
    string p3 = ".*";

    cout << "String: " << s3 << " Pattern: " << p3 << endl;
    cout << "Is Match: " << isMatch(s3, p3) << endl;

    return 0;
}


bool isMatch(string s, string p) {
    int m_str_len = s.size();
    int m_ptn_len = p.size();

    vector<vector<int>> memo(m_str_len + 1, vector<int> (m_ptn_len + 1, -1)) ;

    function <bool(int, int)> dfs = [&] (int p_str_idx, int p_ptn_idx) -> bool {
        if (p_str_idx >= m_str_len && p_ptn_idx >= m_ptn_len) {
            return true;
        }

        if (p_ptn_idx >= m_ptn_len) {
            return false;
        }

        if(memo[p_str_idx][p_ptn_idx] != -1) {
            return memo[p_str_idx][p_ptn_idx] == 1;
        }

        bool is_matching = p_str_idx < m_str_len && (p[p_ptn_idx] == '.' || s[p_str_idx] == p[p_ptn_idx]);

        bool res;
        if (p_ptn_idx + 1 < m_ptn_len && p[p_ptn_idx + 1] == '*') {
            res = dfs(p_str_idx, p_ptn_idx + 2) || (is_matching && dfs(p_str_idx + 1, p_ptn_idx));
        }
        else {
            res = is_matching && dfs(p_str_idx + 1, p_ptn_idx + 1);
        }

        memo[p_str_idx][p_ptn_idx] = res ? 1 : 0;
        
        return res;
    };

    return dfs(0, 0);
}


