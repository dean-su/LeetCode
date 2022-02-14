/*
class NumArray {
public:
    NumArray(vector<int>& nums) {
        nums_ = nums;
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        for (int i = left; i <= right; ++i) {
            sum += nums_[i];
        }
        return sum;
    }
private:
    vector<int> nums_;
};
*/

class NumArray {
public:
    NumArray(vector<int>& nums) {
        if(nums.empty()) return;
        //sums[i] = sums[0]+sum[1]+...+sums[i]
        //sum[i] = sums[i-1] + nums[i] //i >= 1
        sums_ = vector<int>(nums.size(), 0);
        sums_[0] = nums[0];
        for(int i = 1; i< nums.size(); ++i)
            sums_[i] = sums_[i-1] + nums[i];
    }
    
    int sumRange(int left, int right) {
        if(left == 0) return sums_[right];
        //sumRange(i, j) = sums[j] - sums[i-1]
        return sums_[right] - sums_[left-1];
    }
private:
    vector<int> sums_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */