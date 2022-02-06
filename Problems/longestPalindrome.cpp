//
// Created by DeanSu on 2019/9/15.
//Given a string s, find the longest palindromic substring in s.
// You may assume that the maximum length of s is 1000.
//
//Example 1:
//
//Input: "babad"
//Output: "bab"
//Note: "aba" is also a valid answer.
//Example 2:
//
//Input: "cbbd"
//Output: "bb"
#include "longestPalindrome.h"
int expand1(string s, int l, int r){
    while(l >= 0 && r < s.length() && s.at(l) == s.at(r)){
        l--;
        r++;
    }

    return r-l-1;
}
string longestPalindrome1(string s) {
    if (s.length() <=1)
        return "";

    int start = 0, end = 0;
    for (int i = 0; i < s.length(); i++) {
        int l1 = expand1(s, i, i);
        int l2 = expand1(s, i, i+1);
        int l = max(l1, l2);
        if(l > end - start){
            start = i - (l -1) / 2;
            end = i + l / 2;
        }
    }

    return s.substr(start, end+1);

}



// expand in both directions of low and high to find
// maximum length palindrome
string expand(string str, int low, int high)
{
    int len = str.length();

    // run till str[low.high] is a palindrome
    while (low >= 0 && high < len && (str[low] == str[high]))
        low--, high++;		// expand in both directions

    // return palindromic substring
    return str.substr(low + 1, high - low - 1);
}

// Function to find Longest Palindromic Substring in O(n^2) time
// and O(1) space
string LongestPalindromicSubstring(string str)
{
    int len = str.length() - 1;
    // max_str stores the maximum length palindromic substring
    // found so far

    string max_str = "", curr_str;

    // max_length stores the length of maximum length palindromic
    // substring found so far

    int max_length = 0, curr_length;

    // consider every character of given string as mid points and expand
    // in its both directions to find maximum length palindrome

    for (int i = 0; i < len; i++)
    {
        // find a longest odd length palindrome with str[i] as mid point

        curr_str = expand(str, i, i);
        curr_length = curr_str.length();

        // update maximum length palindromic substring if odd length
        // palindrome has greater length

        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }

        // find a longest even length palindrome with str[i] and str[i+1]
        // as mid points. Note that an even length palindrome has two
        // mid points

        curr_str = expand(str, i, i + 1);
        curr_length = curr_str.length();

        // update maximum length palindromic substring if even length
        // palindrome has greater length

        if (curr_length > max_length)
        {
            max_length = curr_length;
            max_str = curr_str;
        }
    }

    return max_str;
}

