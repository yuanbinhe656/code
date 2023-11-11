/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个升序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void cmp(ListNode* ls,ListNode* rs)
    {
        ListNode* lls=ls;
        ListNode* rrs = rs;
        while(lls != nullptr &&rrs != nullptr)
        {
            if(lls->val < rrs->val)
            {
                lls = lls->next; 
            }
            else{
                int val=lls->val;
                ListNode* ne = (ListNode*)malloc(sizeof(ne));
                ne->ListNode(val,lls->next);
                lls->ListNode(rrs->val,ne);
                lls = lls->next;
                rrs = rrs->next;
            }
        }
        if(rrs !=nullptr)
        {
            lls->next = rrs;
        }
        return ls;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        int n;
        while(size == 1)
        {
            n=size/2;
           for(int i = 0;i<n;i++)
           {
            cmp(lists[i],lists[i+n]);
           }
           size = size - n;
        }
        return lists[0];
    }
};
// @lc code=end

