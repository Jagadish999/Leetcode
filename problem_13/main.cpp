#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int romanToInt(string);

int main() {

    cout << romanToInt("LVIII");
    return 0;
}


int romanToInt(string s) {
    unordered_map<string, int> roman_to_int = {
        {"M", 1000},
        {"CM", 900},
        {"D", 500},
        {"CD", 400},
        {"C", 100},
        {"XC", 90},
        {"L", 50},
        {"XL", 40},
        {"X", 10},
        {"IX", 9},
        {"V", 5},
        {"IV", 4},
        {"I", 1}
    };

    int m_decimal_num = 0;
    int m_roman_idx = 0;

    while (m_roman_idx < s.size())
    {
        string m_curr_char = string() + s[m_roman_idx];
        string m_next_char = m_roman_idx < s.size() - 1 ? string() + s[m_roman_idx + 1] : "";

        if (m_next_char != "" && roman_to_int.find(m_curr_char + m_next_char) != roman_to_int.end()) {
            m_decimal_num += roman_to_int[m_curr_char + m_next_char];
            m_roman_idx += 2;

            continue;
        }

        m_decimal_num += roman_to_int[m_curr_char];
        m_roman_idx += 1;

    }
    
    return m_decimal_num;
}