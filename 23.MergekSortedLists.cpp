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

/*
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummy(0);
        ListNode* curr = &dummy;
        
        auto comp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        
    priority_queue<ListNode*, vector<ListNode*>, decltype(comp)>  q(comp);
        
        for (auto node : lists)
           if(node) q.push(node);
        
        while(!q.empty()){
            curr->next = q.top();
            q.pop();
            curr = curr->next;
            
            if(curr->next)
                q.push(curr->next);
        }
        
        curr->next = nullptr;
        return dummy.next;
        
    }
};
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) 
            return NULL;
        
        ListNode* head = lists[0];
        
        for (int i = 1; i < lists.size(); i++){
            head = merge2Lists(head, lists[i]);
        }
        
        return head;
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* head = l1->val <= l2->val? l1 : l2;
        head->next = l1->val <= l2->val ? merge2Lists(l1->next, l2) : merge2Lists(l1, l2->next);
        return head;
        
    }
};