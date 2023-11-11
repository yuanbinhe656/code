/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m =0 , n = 0, pr = 0, flag = 0;
        for(int i= 1;i < prices.size();i++)
        {
            if (prices[i] < prices[i-1])
            {
                if(flag ==1)
                {
                    pr += prices[i-1]- prices[n];
                }
                n =i;
                flag = 0;
            }else if(i == prices.size()-1){
                 pr += prices[i-1]- prices[n];
            else {
                flag =1;
            }
            }
        }
        return pr;
    }
};
// @lc code=end

