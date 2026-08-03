#include <vector>
#include <string>
#include <map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> result;

        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;

        if(s.size() < totalLen) return result;

        std::map<std::string, int> target;

        for (const auto& word: words)
            target[word]++;

        for (int start = 0; start <= s.size() - totalLen; start++) {
            std::map<std::string, int> current;
            bool valid = true;

            for (int i = 0; i < wordCount; i++) {
                std::string word = s.substr(start + i * wordLen, wordLen);

                if (target.find(word) == target.end()) {
                    valid = false;
                    break;
                }

                current[word]++;

                if (current[word] > target[word]) {
                    valid = false;
                    break;
                }
            }

            if (valid) result.push_back(start);

        }
        return result;
    }
};