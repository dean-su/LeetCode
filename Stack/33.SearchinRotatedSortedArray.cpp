class Solution {
public:
  int search(vector<int>& nums, int target) {
      int l = 0, r = nums.size()-1;
      while(l<r) {
          int m = (l+r)/2;
          if(nums[m] == target) return m;
          if(nums[l] <= nums[m]) {
              if(nums[l] <= target && target < nums[m])
                  r = m;
              else
                  l = m+1;
          }else {
              if(nums[m] < target && target <= nums[r])
                  l = m+1;
              else
                  r = m;
          }
      }
      
      if(nums[l]==target)
          return l;
      else if(nums[r] == target)
          return r;
      else
          return -1;
  }
};
