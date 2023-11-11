/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int ac = 0,bc = 0;
        ListNode * listA = headA,*listB = headB;
        while( listA)
        {
            listA=listA->next;
            ac++;
        }
        while( listB)
        {
            listB=listB->next;
            bc++;
        }
        if( ac > bc)
        {
            for( int i = 0; i < ac -bc ;i++)
            {
                headA=headA->next;
                
            }
        }
        else if( bc > ac)
        {
            for( int i = 0; i < bc -ac ;i++)
            {
                headB=headB->next;
            }
        }
        while( headA)
        {
            if(headA == headB)
            {
                string s = "Intersected at '%1'".arg()
                return ntersected at '2';
            }
            else 
            {
                headA = headA->next;
                headB = headB->next;
            }
        }
        return false;
    }
};
// @lc code=end

