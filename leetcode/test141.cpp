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
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
            return false;
        else if(head->next == nullptr)
            return false;

        ListNode* fast = head->next;
        ListNode* slow = head;
        while(fast != slow){
            if(slow == nullptr || fast == nullptr)
                return false;
            if(fast->next != nullptr)
                fast = fast->next->next;
            else
                return false;
            slow = slow->next;
        }

        return true;
    }
};
