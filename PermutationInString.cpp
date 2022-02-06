/*
Complexity Analysis

Time complexity: O(l1+26*(l2-l_1))

Space complexity: O(1)O(1). Constant space is used.
*/

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length())
            return false;
        
        int s1arr[26] = {0};
        for(int i=0; i<s1.length(); i++){
            s1arr[s1[i]-'a']++;
        }
        
        for(int i=0; i<= (s2.length() - s1.length()); i++) {
            int s2arr[26] = {0};
            for(int j=0; j<s1.length(); j++){
                s2arr[s2[i+j] - 'a']++;
            }
            if (matches(s1arr, s2arr))
                return true;
        }
        return false;
    }
    
    bool matches(int s1arr[26], int s2arr[26]) {
        for(int i = 0; i<26; i++){
            if(s1arr[i] != s2arr[i])
                return false;
        }
        return true;
    }
};