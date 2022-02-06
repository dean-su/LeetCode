//
// Created by DeanSu on 2019/9/10.
//Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
//You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//Example:
//
//Given nums = [2, 7, 11, 15], target = 9,
//
//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].
#include "TwoSum.h"

vector<int> twoSum(vector<int>& nums, int target) {
    //map<int, int> m_nums;
    unordered_map<int, int> m_nums;
    vector<int> ret;
    for(int i = 0; i < nums.size(); i++){
        int key = target - nums[i];
        if(m_nums.find(key) != m_nums.end()){
            ret.push_back(i);
            ret.push_back(m_nums[key]);
            break;
        }
        m_nums.insert({nums[i], i});
        //m_nums[nums[i]] = i;
    }

    return ret;
}

