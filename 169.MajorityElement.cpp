class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counter;
        int l = nums.size();
        for (const int num : nums) {
            if(++counter[num] > l/2){
                return num;
            }
        }
        return -1;
    }
};