#include<bits/stdc++.h>
/*
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    }
};
*/
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l<r) {
            int m = l+(r-l)/2;
            if(nums[m]==target){
                return m;
            }else if(nums[m]>target){
                r = m;
            }else {
                l = m+1;
            }
        }
        return l;
    }
};