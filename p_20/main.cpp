#include <string>
#include <vector>


class Solution {
public:
    bool isValid(std::string s) {
        if (s.size() == 0) return false;
        
        if (s[0] == ')' || s[0] == '}' || s[0] == ']') return false;

        std::vector<char> m_opening_braces;

        for (int i = 0; i < s.size(); i++) {
            char m_current_char = s[i];
            char m_last_opening_braces = ' ';

            // Extract last opening braces
            if (m_opening_braces.size() > 0) {
                m_last_opening_braces = m_opening_braces[m_opening_braces.size() - 1];
            }
            
            // push last bracket
            if (m_last_opening_braces == ' ') {
                m_opening_braces.push_back(m_current_char);
                continue;
            }

            // If last bracket is ending
            if (m_last_opening_braces == ']' || m_last_opening_braces == '}' || m_last_opening_braces == ')') {
                return false;
            }

            // Current Bracket is closing
            if (
                m_last_opening_braces == '(' && m_current_char == ')' ||
                m_last_opening_braces == '{' && m_current_char == '}' ||
                m_last_opening_braces == '[' && m_current_char == ']'
            )
            {
                m_opening_braces.pop_back();
                continue;
            }

            m_opening_braces.push_back(m_current_char);
        }

        if (m_opening_braces.size() > 0) return false;

        return true;
    }
};

int main() {


    return 0;
}