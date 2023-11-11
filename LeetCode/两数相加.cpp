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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            int x;
            ListNode* r=ListNode();
            ListNode* dl1=l1;
            ListNode* dl2=l2;
             ListNode* dl3=r;
            while(dl1&&dl2)
            {
                x=dl1->val+dl2->val+dl3->val;
                if(x>=10)
                {
                    dl3->val=x%10;
                    dl3->next=ListNode();
                    dl3=dl3->next;
                    dl3.val=x/2;
                }
                else
                {
                    dl3->val=x;
                     dl3->next=ListNode();
                    dl3=dl3->next;                  
                }
                dl1=dl1->next;
                dl2=dl2->next;
            }
            while(dl1)
            {
                
                x=dl1->val+dl3->val;
                if(x>=10)
                {
                    dl3->val=x%10;
                    dl3->next=ListNode();
                    dl3=dl3->next;
                    dl3.val=x/2;
                }
                else
                {
                    dl3->val=x;
                     dl3->next=ListNode();
                    dl3=dl3->next;                  
                }
                dl1=dl1->next;

            }
            while(dl2)
            {
                x=dl2->val+dl3->val;
                if(x>=10)
                {
                    dl3->val=x%10;
                    dl3->next=ListNode();
                    dl3=dl3->next;
                    dl3.val=x/2;
                }
                else
                {
                    dl3->val=x;
                     dl3->next=ListNode();
                    dl3=dl3->next;                  
                }
                dl2=dl2->next;

            }
    }
    return r;
};
