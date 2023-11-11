/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
       
        int m =0 ,n =0, pr =0,flag =0;
        for (int i = 1 ; i < prices.size();i++)
        {
                if(prices[i] > prices[n] )
                {
                    if( pr < prices[i]- prices[n])
                    {
                        pr = prices[i] - prices[n];
                    }
                } 
                else 
                {
                    n = i;
                }
        }
        return pr;
    }
    
};
// @lc code=end

