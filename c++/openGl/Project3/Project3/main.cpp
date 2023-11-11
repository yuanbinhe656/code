#include<iostream>
#include<deque>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
void swap(TreeNode* root)
{
    if (root->left == NULL && root->right == NULL) {
        return;
    }
    TreeNode* cur = root->left;
    root->left = root->right;
    root->right = cur;
    return;
}

TreeNode* mirrorTree(TreeNode* root) {
    deque<TreeNode*> red;
    if (root == NULL)
    {
        return root;
    }
    swap(root);
    red.push_back(root);
    TreeNode* cur;
    while (!red.empty()) {
        cur = red.front();
        red.pop_front();
        if (cur->left != NULL) {
            swap(cur->left);
            red.push_back(root->left);
        }
        if (cur->right != NULL)
        {
            swap(cur->right);
            red.push_back(cur->right);
        }

    }
    return root;

}
int main()
{
    TreeNode* root = new TreeNode(1);
    TreeNode* root1 = new TreeNode(2);
    TreeNode* root2 = new TreeNode(3);
    TreeNode* root3 = new TreeNode(3);
    TreeNode* root4 = new TreeNode(4);
    TreeNode* root5 = new TreeNode(5);
    TreeNode* root6 = new TreeNode(6);
    root->right = root1;
    root->left = root2;
    root1->right = root3;
    root1->left = root4;
    root2->right = root5;
    root2->left = root6;
   auto ir =  mirrorTree(root);
   cout << ir->val << "," << ir->left->val << "," << ir->right->val;
}