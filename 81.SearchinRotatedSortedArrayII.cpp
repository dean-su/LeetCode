/*class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums[0] == target;
        }
        int m = nums.size()/2;
        vector<int> l(nums.begin(), nums.begin()+m);
        vector<int> r(nums.begin()+m, nums.end());
        if(search(l, target) || search(r, target)) {
            return true;
        }
        return false;
    }
};*/
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;
        
        while (l<r) {
            int m = (l+r)/2;
            
            if (nums[m] == target) {return true;}
            if(nums[m] == nums[l] && nums[m] == nums[r]) {
                l++, r--;
                continue;
            }
            
            if(nums[m] >= nums[l]){
                if (target < nums[m] && target >= nums[l]) {
                    r = m;
                }else{
                    l = m+1;
                }
            }else{
                if (target > nums[m] && target <= nums[r]) {
                    l = m+1;
                }else{
                    r = m;
                }
            }
        }
        
        if (nums[l] == target || nums[r] == target) {
            return true;
        }
        
        return false;
    }
};
