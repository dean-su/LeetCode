//
// Created by DeanSu on 2019/9/11.
//Given a string, find the length of the longest substring without repeating characters.
//
//Example 1:
//
//Input: "abcabcbb"
//Output: 3
//Explanation: The answer is "abc", with the length of 3.
//Example 2:
//
//Input: "bbbbb"
//Output: 1
//Explanation: The answer is "b", with the length of 1.
//Example 3:
//
//Input: "pwwkew"
//Output: 3
//Explanation: The answer is "wke", with the length of 3.
//Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
#include "lengthOfLongestSubstring.h"

int lengthOfLongestSubstring(string s) {
    int l = s.length(), ret = 0;
    map<char, int> mc;

    for(int i = 0, j = 0; j < l; j++) {
        auto iter = mc.find(s.at(j));
        if( iter != mc.end()) {
            i = max(mc.at(s.at(j)), i);
            iter->second  = j+1;
            //ret = max(ret, j-i+1);
        } else {
            mc.insert({s.at(j), j+1});
        }
        ret = max(ret, j-i+1);

    }

    return ret;
}