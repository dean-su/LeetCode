#include<bits/stdc++.h>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //nums = [-2,1,-3,4,-1,2,1,-5,4]
        //f =    [-2,1,-2,4, 3,5,6, 1,5]
        //f[i] = f[i-1] > 0 ? nums[i] + f[i-1] : nums[i]
        vector<int> f(nums.size());
        f[0] = nums[0];
        for(int i=1; i < nums.size(); i++){
            f[i] = max(nums[i]+f[i-1], nums[i]);
        }
        return *std::max_element(f.begin(), f.end());
    }
};