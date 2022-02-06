#include<bits/stdc++.h>
#include<iostream>
using namespace std;


 int lengthOfLongestSubstring(string s) {
        int l = s.length(), ret = 0;
        map<char, int> mc;
        
        for(int i = 0, j = 0; j < l; j++) {
            auto iter = mc.find(s.at(j));
            if(iter != mc.end()){
                i = max(mc.at(s.at(j)), i);
                iter->second = j+1;
            }
            ret = max(ret, j-i+1);
            mc.insert({s.at(j), j+1});
        }
        
        return ret;
}

int main() {
    string s = "abcabcbb";
    cout<< s <<" " << lengthOfLongestSubstring(s);
}