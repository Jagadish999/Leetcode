#include <iostream>
#include <string>

using namespace std;

int myAtoi(string s);

int main() {
    string m_str_1 = "42";
    string m_str_2 = "20000000000000000000";
    string m_str_3 = "1337c0d3";
    string m_str_4 = "0-1";
    string m_str_5 = "words and 987";

    int m_atoi_1 = myAtoi(m_str_2);

    cout << "Atoi of " << m_str_2 << " is: " << m_atoi_1 << "\n";

    return 0;
}

int myAtoi(string s) {
    if(s == "") return 0;

    long long result = 0;
    int ch_idx = 0;
    int sign = 1;

    while (s[ch_idx] == ' ') ch_idx++;
    
    if (ch_idx < s.size()) {

        if (s[ch_idx] == '-'){
            ch_idx++;
            sign = -1;
        }
        else if (s[ch_idx] == '+')
        {
            ch_idx++;
        }
    }

    while (isdigit(s[ch_idx]))
    {
        int digit = s[ch_idx] - '0';
        
        result = result * 10 + digit;

        ch_idx++;

        if (sign * result >= INT_MAX) return INT_MAX;
        else if (sign * result < INT_MIN) return INT_MIN;
    }

    return static_cast<int>(sign * result);
}