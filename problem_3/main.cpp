#include "Solution.h"

#include <iostream>
#include <string>

int main() {
    Solution soln;

    std::string test = "abcabcbb";

    std::cout << soln.lengthOfLongestSubstring(test) << std::endl;

    return 0;
}