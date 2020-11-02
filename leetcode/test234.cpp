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
    bool isPalindrome(ListNode* head) {
        if(head == nullptr)
            return true;
        ListNode* slow = head;
        ListNode* fast = head->next;
        if(fast == nullptr)
            return true;
        while(fast->next != nullptr){
            fast = fast->next;
            if(fast->next != nullptr)
            {
                fast = fast->next;
                slow = slow->next;

            }
        }


        ListNode* firstEnd = slow->next;

        //reverse
        slow = slow->next;  //后半段逆序

        ListNode* prePtr = nullptr;
        while(slow->next != nullptr){
            fast = slow->next;
            slow->next = prePtr;
            prePtr = slow;
            slow = fast;
        }
        slow->next = prePtr;

        fast = head;  //前半段正序
        //decide
        while(slow != nullptr ){
            if(slow->val != fast->val)
                return false;
            slow = slow->next;
            fast = fast->next;
        }
        return true;
    }
};
