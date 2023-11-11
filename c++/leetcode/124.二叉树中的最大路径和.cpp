/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
      
        
        int max = root->val;
        int min=root->val;
        int x = path(root,max,min);
        if(min<0)
        {
            return min;
        }
        if(x > max)
        {
            return x;
        }
        else{
            return max;
        }
        

    }
      int path(TreeNode* root,int &max,int &min)
        {
            if(root->val==NULL)
            {
                return 15;
            }
            if(root->val>min)
            {
                min=root->val;
            }
            int l=root->val,r=root->val,m=root->val;
            if(root->left == NULL&&root->right ==NULL)
            {

                return root->val;
            }
             if(root->left != NULL)
            {
               
               root->left->val = path(root->left,max,min);
                l+=root->left->val;
                if(root->right ==NULL&&root->left->val>max)
                {
                    max = root->left->val;
                }

            }
              if(root->right !=NULL)
                 {
                    
                    root->right->val = path(root->right,max,min);
                    r+=root->right->val;
                    if(root->left !=NULL)
                    {
                        m = r+l-m;
                        if(r>l&&root->right->val>max)
                        {
                            max = root->right->val;
                        }
                        else if(r <=l&&root->left->val > max)
                        {
                            max = root->left->val;
                        }
                    }
                    else if(root->right->val >max)
                    {
                        max = root->right->val;
                    }
                 }
                if(m>r && m>l && m>0 &&m>max)
                {
                    max = m;
                }
                else if(l>r && l>m && l>0 &&l>max)
                {
                    max = l;

                }
                else if(r>m && r>l && r>0 &&r>max)
                {
                    max = r;
                }
                 return root->val;

               

        }
};
// @lc code=end

