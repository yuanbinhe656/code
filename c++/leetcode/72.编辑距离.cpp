/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size() + 1;
        int len2 = word2.size() + 1;
        int data[len1][len2];
        
        for(int i = 0 ;i < len1; i++)
        {
            data[i][0] = i;
        }
        for(int j = 0; j < len2 ;j++)
        {
            data[0][j] = j;
        }
        int left ,up, down;
        
        for(int i = 1; i < len1 ; i++)
        {
            for(int j = 1; j < len2 ; j++)
            {
                if(word1[i -1] == word2[j -1])
                {
                    data[i][j] = data[i-1][j-1];
                }
                else
                {
                    left = data[i-1][j] +  1;
                    up = data[i][j-1]+ 1 ;
                    down = data[i-1][j-1] + 1;
                    data[i][j]=min(down ,min(up,left));
                   
                }
                cout<<data[i][j] << "  ";
                if(j == len2-1)
                {
                    cout<<endl;
                }
            }
        }
        return data[len1-1][len2-1];

    }
};
// @lc code=end

