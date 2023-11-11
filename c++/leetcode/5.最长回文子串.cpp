/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        string::iterator iter=s.begin();
        string::iterator iter1,iter2,itera,iterb,iterd=s.end();
        int max = 0,num;
        while(iter != iterd)
        {
            iter2=iter1=iter;
            while(iter1 != s.begin() && iter2 != s.end()-1) {
                if(*(--iter1) != *(++iter2)) {
                    num = distance(iter1,iter2) +1;
                    if (num >max) {                     
                        max =num;
                        itera = iter1;
                        iterb = iter2;
                        iterd = s.end() - max;
                    }
                    break;
                }
                
                
            }
            iter++;
        }
        string rs(itera,iterb);
        return rs;
    }
};
// @lc code=end

