#include <vector>
#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s);

int main() {
    string str = "abcaexbcbb";

    int largest_sub_str = lengthOfLongestSubstring(str);
    cout << "Largest SubStr is: " << largest_sub_str;

    return 0;
}


int lengthOfLongestSubstring(string s) {
    vector<bool>count(256,0);
    int first=0,second=0,len=0;

    while(second<s.size())
    {
        while(count[s[second]])
        {
            cout << "Frs: " << s[first] << "\n";

            count[s[first]]=0;
            first++;

        }
        cout << "Sec: " << s[second] << "\n";

        count[s[second]]=1;
        len=max(len,second-first+1);
        second++;
    }
    return len;
}

// int lengthOfLongestSubstring(string s) {
//     int largest_sub_str_len = 0;

//     for (int first_char_idx = 0; first_char_idx < s.size(); first_char_idx++) {
//         unordered_map<char, bool> prev_records;

//         char first_char = s[first_char_idx];
//         prev_records[first_char] = true;

//         string sub_str = "";
//         sub_str += first_char;

//         for (int nxt_char_idx = first_char_idx + 1; nxt_char_idx < s.size(); nxt_char_idx++) {
//             char nxt_char = s[nxt_char_idx];

//             if (prev_records.find(nxt_char) != prev_records.end()) {
//                 break;
//             }
//             else {
//                 sub_str += nxt_char;
//                 prev_records[nxt_char] = true;
//             }
//         }

//         if (sub_str.size() > largest_sub_str_len) {
//             largest_sub_str_len = sub_str.size();
//         }
//     }

//     return largest_sub_str_len;
// }