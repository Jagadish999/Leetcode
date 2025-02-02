#include "Solution.h"

#include <iostream>
#include <string>

int main() {

    Solution soln;
    std::string check_str = "babad";

    std::string longest_palindrome = soln.longestPalindrome(check_str);

    std::cout << "Longest Palindrome is: " << longest_palindrome << std::endl;

    return 0;
}