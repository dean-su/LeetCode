#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static int lengthOfLIS(vector<int>& nums) {
        vector<int> LIS(nums.size(),1);
        for(int i=0;i <nums.size();i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                    LIS[i]=max(LIS[i],1+LIS[j]);
            }
        }
        return *max_element(LIS.begin(),LIS.end());
    }
};

int main(){
    vector<int> nums{10,9,2,5,3,7,101,18};
    Solution::lengthOfLIS(nums);
    //Solution s;
    //cout<<s.lengthOfLIS(nums);
}