class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int counter = 0, sum = 0;
        unordered_map<int, int> mmap{{0,1}};
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            counter += mmap[sum-k];
            mmap[sum]++;
        }
        return counter;
    }
};