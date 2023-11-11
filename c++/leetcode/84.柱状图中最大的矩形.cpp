/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
   auto maxitr = max_element(heights.begin(),heights.end());
        int max = *maxitr;

        vector<vector<int>> v(heights.size(),vector<int>(max));
        int data;
        int result = 0;
        for(int i = 0 ;i < heights.size(); i++)
        {
            int j = i;
            data = 0;
            while(heights[j] >= 1 && j < heights.size())
            {
                data ++;
                j++;
            }
            while(i < j)
            {
                v[i][0] = data;
                i++; 
            }
            if(data > result)
            {
                result = data;
            }
        }
        for(int j =1 ;j < max; j++)
        {
            for(int i = 0; i < heights.size(); i++)
            {
                 data = 0;
                int z = i;
                while(heights[z] <= j + 1 &&z <= v[i][j] /j +i )
                {
                    data ++;
                    z++;
                }
                while(i < z)
                {
                    v[i][j] = data * (j+1);
                    i++;
                }
                if(data > max)
                {
                    max = v[i][j] = data * (j+1);
                }
            }
        }
        return result;

    }
};
// @lc code=end

