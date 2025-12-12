// https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include <string>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;

        string currSubStr{ "" };  // not neeeded actually
        unordered_map<char, size_t> currSurStrCharMap;
        int maxLen{}, currLen{};

        for (size_t i = 0; i < s.length(); i++) {
            auto foundIt = currSurStrCharMap.find(s[i]);
            if (foundIt != currSurStrCharMap.end()) {
                // s[i] is repeated hence cannot included to current
                if (currLen > maxLen) {
                    maxLen = currLen;
                }
                auto j = foundIt->second + 1; // access before claring the map
                // clear current charcter map
                currSurStrCharMap.clear();
                currLen = 0;
                currSubStr = "";
                // add all characters after previous occurance of
                // the repeated character till current charcter
                while (j <= i) {
                    currSurStrCharMap.insert({ s[j], j });
                    j++;
                    currLen++;
                    currSubStr += s[j];
                }
            }
            else {
                // s[i] is not repeated
                currSubStr += s[i];
                currLen += 1;
                currSurStrCharMap.insert({ s[i], i });
            }
        }

        if (currLen > maxLen)
            maxLen = currLen;

        return maxLen;
    }
};

int lc_longest_substr_wo_repeated_chars_main()
{
    Solution sln;

    vector<string> inputs{ "123456 3789", "abcdefgh123456 3789", "abcabcbb", "bbbbb", "pwwkew", "abc", "a", "aabbcc", "dvdf"};
    //vector<string> inputs{ "bb" };

    for (auto s : inputs) {
        cout << s << ":" 
             << sln.lengthOfLongestSubstring(s) << endl;
    }
    
    return 0;
}