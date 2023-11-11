// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem142.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
// 若有环快指针一定会相遇慢指针，慢指针走一圈后，快指针正好比慢指针多走1格
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
    ListNode * low = head;
    ListNode * hight = head;
    int flag = 0;
    if(head == NULL)
    {
        return NULL;
    }
    while(hight->next != NULL&&hight->next->next != NULL)
    {
        low = low->next;
        hight = hight->next->next;
        if( low == hight)
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        return NULL;
    }
    low = head;
    while(low != hight)
    {
        low=low->next;
        hight = hight->next;
      
    }
    return low;
    }
};
// @lc code=end

