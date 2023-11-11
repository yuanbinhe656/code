/*
 * @lc app=leetcode.cn id=123 lang=cpp
 *
 * [123] 买卖股票的最佳时机 III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int number = prices.size();
        int m,n;
        int data[number][3];
        int max=prices[0],min=prices[0];
        data[0][0]=data[number-1][1]=0;
        for(int i = 1;i < prices.size();i++)
        {
            if(prices[i]<min)
            {
                
                data[i][0] = max - min;
                min=max = prices[i];

            } else if(prices[i] > max)
            {
                max = prices[i];
                data[i][0] = max -min;

            }
            else{
                data[i][0]=max -min;
            }

            
        }
           m=max=prices[number-1],min=prices[number-1];
        for(int i = number -2;i > -1;i --)
        {
            if(prices[i] < min)
            {
                min =prices[i];
                max = m;
                 data[i][1] = max - min;
                 data[i][3]=data[i][0]+data[i][1];
            }
            else if(prices[i]> max)
            {
                m = prices[i];
                data[i][1] = max - min;
                 data[i][3]=data[i][0]+data[i][1];
            }
            else{
                data[i][1] = max - min;
                 data[i][3]=data[i][0]+data[i][1];
            }
        }
        int pr = data[number-1][3];
        for(int i = number -2;i > -1;i --)
        {
            if(data[i][3]>pr)
            {
                pr = data[i][3];
            }
        }
        return pr;
    }
};
// @lc code=end

