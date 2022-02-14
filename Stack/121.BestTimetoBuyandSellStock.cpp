/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 0) return 0;
        vector<int> min_prices(n);
        vector<int> max_profit(n);
        min_prices[0] = prices[0];
        max_profit[0] = 0;
        for (int i = 1; i < n; i++) {
            min_prices[i] = min(min_prices[i-1], prices[i]);
            max_profit[i] = max(max_profit[i-1], prices[i]-min_prices[i]);
        }
        return max_profit[n-1];
    }
};
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;
        
        vector<int> profits(n, 0);
        profits[0] = prices[0];
        for (int i = 1; i < n; i++) {
            profits[i-1] = prices[i] - prices[i-1];
        }
        return max(0, maxSubProfits(profits));
    }
    
private:    
    int maxSubProfits(vector<int> profits) {
        //f[i] = f[i-1] > 0 ? num[i] + f[i-1] : num[i]
        int n = profits.size();
        vector<int> sumProfits(n, 0);
        sumProfits[0] = profits[0];
        int maxProfit = profits[0];
        for (int i = 1; i < n; i++) {
            sumProfits[i] = max(profits[i], profits[i]+sumProfits[i-1]);
            
            if (maxProfit < sumProfits[i])
                maxProfit = sumProfits[i];
        }

        return maxProfit;
        
        
    }
    
};