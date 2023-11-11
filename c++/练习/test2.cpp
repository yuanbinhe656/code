#include<iostream>
#include <string>
#include <vector>
#include <stack>
#include <deque>
#include <algorithm>
using namespace std;
  struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
    bool peek(TreeNode* A, TreeNode* B)
    {
        if(A == NULL && B== NULL)
        {
            return true;
        }
        else if( B && A == NULL )
        {
            return false;
        }
        else if(A->val == B->val)
        {
            return peek(A->left,B->left)&&peek(A->right,B->right);
        }
        else
        {
            return false;
        }
    }
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        TreeNode* head = A;
        deque<TreeNode*> data;
        data.push_back(head);
       while(!data.empty())
       {
           head = data.front();
           if(peek(head,B))
           {
               return true;
           }
           else
           {
            if(head->left)
            {
                data.push_back(head->left);
            }
            if(head->right)
            {
                data.push_back(head->right);
            }
           }
       }
       return false;
    }
        double p( int &n,vector<double> &data)
    {
        int i = 1;
        if(n == 1)
        {
            return data[0];
        }
        i = 2;
        while(  n )
        {
            i = i *2;
        }
        if(i == n)
        {
        	n = i;
        	return data[i/2];
		}
        i = i/2;
        n = i;
        return data[i - 1];
    }
    double myPow(double x, int n) {
       int size = n;
       double s = x;
       double ret = 1;
        while(size )
        {
            
            if(size & 1)
            {
                ret = ret * s;
            }
            size = size>> 1;
            s = s * s;
            
        }
        return ret;
    }



    bool traversal(vector<int>& postorder,int left,int right){
        // 1.  确认递归返回条件
        if(left>=right) return true;
        
        // 2. 查询第一个大于root节点数值的索引
        int mid=left;
        int root=postorder[right];
        while(postorder[mid]<root)  mid++;

        // 3. 确认mid右侧数值始终大于root节点
        int temp=mid;
        while(temp<right){
            if(postorder[temp++]<root)
                return false;
        }

        // 4. 递归查询[left,mid-1]、[mid,right-1] 是否同样满足条件
        return traversal(postorder,left,mid-1) && traversal(postorder,mid,right-1);
    }
     bool verifyPostorder(vector<int>& postorder) {
        stack<int> stk;
        int root = 2147483647;
        for(int i = postorder.size() - 1 ; i >= 0 ; i--)
        {
            if(postorder[i] > root) return false;
            while(!stk.empty() && stk.top() > postorder[i])
            {
                root = stk.top();
                stk.pop();
            }
            stk.push(postorder[i]);
        }
        return true;
    }
    bool checkDynasty(vector<int>& place) {
        int m = 0;
        int n = 0;
        int cnt=  0;
        if(place.size() == 0)
        {
            return true;
        }
       
        for(int  i = 0; i < place.size() ; i++)
        {
            
            if(m == 0)
            {
                if(n == 0) // 前几位均为0
                {
                    m = place[i];
                    n = place[i];
                }
                else if(place[i] == 0)
                {
                    cnt++;
                }
                else if(abs(place[i] - n) >= cnt&& cnt %2 ==abs(place[i] - n)  ) // 中间右若干零
                {
                    m = place[i];
                    n = place[i];
                    cnt = 0;
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(place[i] == 0)
                {
                    cnt++;
                    m = place[i];
                }
                else if(abs(place[i] - m) == 1) 
                {
                    m = place[i];
                }
                else
                {
                    return false;
                }
            }
            cout << "m" << m << "n" << n<< "place " << place[i] << endl;
        }
        return true;
    }
        int bestTiming(vector<int>& prices) {
        int max = INT_MIN;
        if(prices.size() < 2)
        {
            return 0;
        }
        int m = prices[0],n = prices[0];
        
        for(int i = 0; i < prices.size() ; i++)
        {
            
            if(prices[i] >= n )
            {
                n = prices[i];
            }
            else 
            {
                if(max < n - m)
                {
                    max = n - m;
                }
                if( m > prices[i])
                {
                    m = prices[i];
                }
                n = prices[i];
            }
           
        }
        return  max;
    }
        int jewelleryValue(vector<vector<int>>& grid) {
        if(grid.size() == 0)
        {
            return 0;
        }
        if(grid.size() == 1&&grid[1].size() == 1)
        {
            return grid[0][0];
        }
        
        for(int  i = 1; i < grid.size(); i++)
        {
           grid[i][0] = grid[i-1][0] + grid[i][0];
        }
        for(int  i = 1; i < grid[0].size(); i++)
        {
        	  grid[0][i] = grid[0][i-1] +grid[0][i] ;
           
        }
        int m = 0;
         for(auto it : grid)
        {
        	for(auto itr :it)
        	{
        		cout << itr << " " ;
			}
        	cout << endl;
		}
        for(int  i = 1; i < grid.size(); i++)
        {
            for(int j = 1; j < grid[0].size(); j++)
            {
                grid[i][j] = max(grid[i][j-1],grid[i-1][j]) + grid[i][j];
                cout << " i " << i << " j " << j<< endl;

            }
        }
        for(auto it : grid)
        {
        	for(auto itr :it)
        	{
        		cout << itr << " " ;
			}
        	cout << endl;
		}
        cout << endl;
        return grid[grid.size()-1][grid[0].size() - 1];
    }
        int crackNumber(int ciphertext) {
        int a = 1, b = 0, c = 0,m = 1;
        int  n = 0;
        string str = to_string(ciphertext);
        for(int i = 0; i < str.size(); i++)
        {
             b = b+a;
            if(str[i] > '0'&&str[i] < '2')
            {
               
               c= c+a;
            }
            else if( str[i] == '2')
            {
               
                if(i+ 1 < str.size()&&str[i+1] < '6')
                {
                    c = c + a;
                }
            }
            cout  << " a : " <<a<< " b : " <<b<< " c : " <<c<< endl;
            a = b;
            b = c;
            c = 0;
             cout  << " a : " <<a<< " b : " <<b<< " c : " <<c<< endl;
            
        }
        return b + a;
    }
	class Solution {
		}; 

    int merge(vector<int> & record,vector<int> & tmp,int l ,int r)
    {
        if(l >= r)
        {
            return 0;
        }
        int mid = (l + r) / 2;
        int inv_count = merge(record,tmp,l,mid) + merge(record,tmp,mid + 1,r);
        int i = l,j = mid + 1, pos = l;
        while(i <= mid && j <= r)
        {
            if(record[i] <= record[j])
            {
                tmp[pos] = record[i];
                i++;
                inv_count += (j - mid - 1);
				cout << inv_count << " " << " j" << j << "mid" << mid;
            }
            else
            {
                tmp[pos] = record[j];
                j++;
            }
            pos++;
        } 
        for(int k = i; k <= mid; k++)
        {
            tmp[pos] = record[i];
            inv_count += j - mid - 1;
            pos++;
            cout << inv_count << " " ;
        }
        for(int k = j; k <= j; k++)
        {
            tmp[pos] = record[j];
            pos++;
        }
        copy(tmp.begin()+l,tmp.begin() + r + 1, record.begin() + l);
        return inv_count;
    }
    int reversePairs(vector<int>& record) {
        vector<int> tmp(record.size());

        return merge(record,tmp, 0, record.size() - 1);
    }
class A{
//	int s;
//	int v;
//	public:
//	static int st;
//	inline void retr()
//	{
//		int s;
//	}
}; 

int main()
{
	A a;
	A b;
 	cout << &a<<endl;
 	cout << &b;
	
	return 0;
 } 
