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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        ListNode* la;
        ListNode* cur;
        if(l1->val < l2->val)
        {
            la = l1;
            cur = l1;
            l1 = l1->next;
        }
        else{
            la = l2;
            cur = l2;
            l2 = l2->next;
        }

        while(l1 != nullptr || l2 != nullptr)
        {
            if(l1 == nullptr)
            {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
                continue;
            }
            if(l2 == nullptr)
            {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
                continue;
            }

            if(l1->val < l2->val)
            {
                cur->next = l1;
                l1 = l1->next;
                cur = cur->next;
            }else
            {
                cur->next = l2;
                l2 = l2->next;
                cur = cur->next;
            }
        }
        return la;
    }
};
