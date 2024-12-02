#include "Solution.h"

#include <string>
#include <unordered_map>


int Solution::lengthOfLongestSubstring(std::string s) {
    if(s == "") {
        return 0;
    }
    else if (s.size() == 1) {
        return 1;
    }

    std::unordered_map<char, int> hash_map;
    std::string sub_str = "";

    int longest_sub_str_size = 0;

    for(int start = 0; start < s.size() - 1; start++) {
        sub_str += s[start];
        hash_map[s[start]] = start;

        for (int sec = start + 1; sec < s.size(); sec++) {
            char temp_str = s[sec];

            if (hash_map.find(temp_str) != hash_map.end()){
                break;
            }

            sub_str += s[sec];
            hash_map[s[sec]] = sec;
        }

        if(sub_str.size() > longest_sub_str_size) {
            longest_sub_str_size = sub_str.size();
        }

        sub_str = "";
        hash_map.clear();
    }

    return longest_sub_str_size;
}
