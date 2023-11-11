/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s = (nums1.size() + nums2.size());
        if(s == 0)
        {
             return 0;
        }
        if(s == 1)
        {
            if(nums1.size() == 1)
            {
                return nums1[0];
            }
            else 
            {
                return nums2[0];
            }
        }
        int num = 0;
        int data = 0;
        int odd = 0;
        int ndd = 0;
        auto item1 = nums1.begin();
        auto item2 = nums2.begin();
        while(item1 != nums1.end()  &&item2 != nums2.end())
        {
            if(*item1 > *item2)
            {
                num++;
                odd = ndd;
                ndd = *item2;
                item2++;
                
                
            }
            else
            {
                num++;
                odd = ndd;
                ndd = *item1;
                item1++;

            }
            if(num == s/2 + 1)
                {
                    break;

                }
        }
        
        if( num < s/2 + 1)
        {
            if(item1 == nums1.end())
            {
                for(int i = num ; i < s/2 + 1; i++)
                {
                    odd = ndd;
                    ndd = *item2;
                    item2++;
                }
            } 
            else
            {
            for(int i = num ; i < s/2+1; i++)
                {
                    odd = ndd;
                    ndd = *item1;
                    item1++;
                }
            }  
        }
              if( s % 2 == 1)
                {
                    return ndd;
                }
                else 
                {
                   return (double)(ndd + odd)/2;
                    
                }
        return 0;
        
    }
};
// @lc code=end

