#include <vector>
#include <iostream>

using namespace std;

string convert(string s, int numRows);

int main() {
    string m_str = "PAYPALISHIRING";
    int m_row_num = 4;

    string m_converted_str = convert(m_str, m_row_num);
    cout << m_converted_str;


    return 0;
}

string convert(string s, int numRows) {
    if (numRows == 1) return s;

    vector<string> m_str_vect (numRows, "");

    int row_num = 0;
    int col_num = 0;

    bool m_is_move_down = true;
    int row_count = numRows;

    for (char ch: s) {
        m_str_vect[row_num] += ch;
        
        if (m_is_move_down) {
            row_num += 1;
        }
        else {
            row_num -= 1;
        }

        if (row_num == numRows) {
            row_num = numRows - 2;
            m_is_move_down = false;
        }
        else if (row_num < 0)
        {
            row_num = 1;
            m_is_move_down = true;
        }
    }

    string m_zig_zag_str = "";

    for (string str: m_str_vect) {
        m_zig_zag_str += str;
    }

    return m_zig_zag_str;
}