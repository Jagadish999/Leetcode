#include <iostream>
#include <string>

using namespace std;

int main() {
    int check_num = 121;

    bool is_palindrome = isPalindrome(check_num);

    return 0;
}

bool isPalindrome(int x) {
    if (x < 0) return false;

    string num_to_str = to_string(x);

    int first_idx = 0;
    int last_idx = num_to_str.size() - 1;


    while (first_idx <= last_idx) {
        if (num_to_str[first_idx] != num_to_str[last_idx]) return false;

        first_idx++;
        last_idx--;
    }

    return true;
}
