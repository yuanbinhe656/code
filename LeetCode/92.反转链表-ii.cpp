/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* left_head = head;
        ListNode* left_end,* old;
        ListNode* next = NULL,* new_head;
        old = left_head;
        for(int i = 1; i < left; i++)
        {
            old = left_head;
            left_head = left_head->next;
        }
        
        
        
        left_end = left_head;
        for( int i = left; i <= right; i++)
        {
            
           new_head = left_head;
           left_head = left_head->next;
           new_head->next = next;
           next = new_head;
            
        }
        left_end->next = left_head;
        if(left == 1)
        {
            return new_head;
        }
        old->next = new_head;
        
        return head;
    }
};
// @lc code=end

