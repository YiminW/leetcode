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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr or head->next == nullptr)
            return head;

        long int num = 1;
        ListNode* count = head;
        while(count->next != nullptr){
            num++;
            count = count->next;
        }
        //delete count;
        k = k%num;
        ListNode* fast = head;
        ListNode* slow = head;
        while(k){
            if(fast -> next != nullptr)
                fast = fast->next;
            else
                fast = head;
            k--;
        }

        if(slow == fast)
            return head;

        while(fast->next != nullptr){
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = head;
        if(slow->next != nullptr)
            head = slow->next;
        slow->next = nullptr;
        //delete fast;
        return head;
    }
};
