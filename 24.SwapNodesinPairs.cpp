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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;
        
        ListNode dummy(0);
        ListNode* curr = &dummy;
        dummy.next = head;
        while(curr && curr->next && curr->next->next) {
            ListNode* p1 = curr->next;
            ListNode* p2 = p1->next;
            
            curr->next = p2;
            p1->next = p2->next;
            p2->next = p1;
            
            curr = p1;
        }
        
        return dummy.next;
    }
};