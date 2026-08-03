#include <string>
#include <vector>

using namespace std;

vector<string> letterCombinations(string digits);

int main() {

    return 0;
}

vector<string> letterCombinations(string digits) {
    vector<string> mapping = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    vector <string> result = {""};

    for (char digit: digits) {
        int m_num = digit - '0';
        string letters = mapping[m_num];

        vector <string> temp;

        for (const string & prefix: result) {
            for (char ch: letters) {
                temp.push_back(prefix + ch);
            }
        }

        result = temp;
    }

    return result;
}