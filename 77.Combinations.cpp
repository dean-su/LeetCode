#include<bits/stdc++.h>

class Solution {
public:
    vector<vector<int > >res;
    void loop(int i,int k,int n,vector<int >&temp)
    {
        if(temp.size()==k)
        {
            res.push_back(temp);
            return;  
        }
        if(i>n)
        {
            return ;
        }
        temp.push_back(i);
        loop(i+1,k,n,temp);
        temp.pop_back();
        loop(i+1,k,n,temp);
        
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int >temp;
        loop(1,k,n,temp);
        return res;
    }
};