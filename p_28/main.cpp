#include <string>
#include <iostream>


class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() > haystack.size()) return -1;

        int starting = 0;

        while (starting <= haystack.size() - needle.size())
        {
            std::string splittedStr = haystack.substr(starting, needle.size());

            if (splittedStr == needle) return starting;

            starting += 1;
        }
        
        return -1;
    }
};