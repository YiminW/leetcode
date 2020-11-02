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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr || k <= 1)
            return head;
    
        ListNode* curStart = head;
        ListNode* curEnd = head;
        ListNode* lastEnd = nullptr;
        ListNode* nextStart = nullptr;
        int count;
        bool first = true;
        while(curEnd != nullptr){
            count = 1;
            while(count != k)
            {
                if(curEnd -> next != nullptr){
                    curEnd = curEnd->next;
                    count++;
                }
                else{
                    if(lastEnd != nullptr){
                        lastEnd->next = nextStart;
                        return head;
                    }
                }
            }
            nextStart = curEnd->next;
            curEnd->next = nullptr;
            
            curEnd = curStart;
            //reverse
            ListNode* prePtr = nullptr;
            ListNode* nextPtr = nullptr;
            while(curStart -> next != nullptr){
                nextPtr = curStart->next;
                curStart->next = prePtr;
                prePtr = curStart;
                curStart = nextPtr;
            }
            curStart->next = prePtr;
            if(first){
                head = curStart;
                first = false;
            }



            if(lastEnd != nullptr){
                lastEnd->next = curStart;
            }
            lastEnd = curEnd;
            //curEnd->next = nextStart;

            curStart = nextStart;
            curEnd = nextStart;


        }

        return head;
    }
};
