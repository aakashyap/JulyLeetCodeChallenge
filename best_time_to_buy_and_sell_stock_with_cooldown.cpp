/*

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times) with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:

Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]

*/

class Solution {
    int size;
    vector<vector<int>> dp;
    int util(int buyPrice,int result,const vector<int>& prices,int i) {
        if (i >= size) return 0;
        bool buy = buyPrice != -1;
        if (dp[i][buy] != -1) {
            return dp[i][buy];
        }
        if (buy) { /* sell or not sell*/
            return dp[i][buy] = max(prices[i]+util(-1,result+(prices[i]-buyPrice),prices,i+2),util(buyPrice,result,prices,i+1));
        } else { /* buy or not buy */
            return dp[i][buy] = max(-prices[i]+util(prices[i],result,prices,i+1),util(-1,result,prices,i+1));
        }
    }
public:
    int maxProfit(vector<int>& prices) {
        size = prices.size();
        dp.resize(size);
        for(int i = 0;i<size;++i) {
            dp[i].resize(2,-1);
        }
        return util(-1,0,prices,0);
    }
};