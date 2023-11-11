/*
 * @lc app=leetcode.cn id=41 lang=cpp
 *
 * [41] 缺失的第一个正数
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int result,s;


        for(int i=0;i<nums.size();i++)
        {
            while(nums[i]>0 && nums[i]-1!=i &&nums[i]<nums.size()+1&&nums[i]!=nums[nums[i]-1]) {
                s = nums[i];
                nums[i] = nums[s-1];
                nums[s-1] = s;
            }
        }
    

        int i= 0;

        while(i<nums.size())
        {
            if(nums[i]!=i+1)
            {
                s=i+1;
                break;
            }
            i++;
        }
        if(i==nums.size())
        {
            return i+1;
        }
        else 
            return s;
        
    }
     
    
};
// @lc code=end
