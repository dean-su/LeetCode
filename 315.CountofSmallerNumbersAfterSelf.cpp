class BIT {
public:
    BIT(int n) : sum_(n+1,0) {}
    void update(int i, int delta) {
        while(i<sum_.size()){
            sum_[i] += delta;
            i += lowbit(i);
        }
    }
    
    int query(int i) const {
        int sum = 0;
        while(i>0){
            sum += sum_[i];
            i -= lowbit(i);
        }
        return sum;
    }
    
private:
    static inline int lowbit(int x) {return x&(-x);}
    vector<int> sum_;
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> nums_sorted(nums.begin(), nums.end());
        unordered_map<int, int> nums_ranked;
        int rank = 0;
        for(const int num : nums_sorted)
            nums_ranked[num] = ++rank;
        
        vector<int> res;
        BIT tree(nums_ranked.size());
        
        for(int i = nums.size() - 1; i >= 0; i--) {
            res.push_back(tree.query(nums_ranked[nums[i]] - 1));
            tree.update(nums_ranked[nums[i]], 1);
        }
        
        std::reverse(res.begin(), res.end());
        return res;
    }
};