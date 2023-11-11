/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
    Node* headA = head;
    Node* w = head;
    if(head == NULL)
    {
        return NULL;
    }
    Node* headB = new Node(head->val);
    Node* result = headB;

    // 通过间接将headB指向headA的random，再通过headA->random指向headB对应的
    headB->next = headA->next;
    headA->next = headB;
    headA = headB->next;
    while(headA != NULL)
    {
        headB =  new Node(headA->val); 
        headB->next = headA->next;
        headA->next = headB;
        headA = headB->next;
    }
    headA = head;
    headB = result;
    while(headA)
    {
        headB = headA->next;
        if(headA->random == NULL)
        {
            headB->random = nullptr;
        }
        else
        {
           headB->random  = headA->random->next;
        }
         
        headA = headA->next->next;
        
    }

    headA = head;
    headB = result;
    while(headB->next)
    {
        
        headA->next = headB->next;
        headA = headB->next;
        headB->next = headA->next;
        headB = headB->next;
    }   
    headA->next = NULL;
    return result;
    }
};
// @lc code=end

