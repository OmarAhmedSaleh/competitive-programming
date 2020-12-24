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
    void scan(ListNode* head){
        if(head == nullptr || head->next == nullptr){return;}
        ListNode* nextComponentHead = head->next->next;
        if(nextComponentHead == nullptr){
            head->next->next = head;
            head->next = nullptr;
            return;
        }
        ListNode* nextComponentHeadNext = head->next->next->next;
        
        if(nextComponentHeadNext == nullptr){
            head->next->next = head;
            head->next = nextComponentHead;
            return;
        }
        head->next->next = head;
        head->next = nextComponentHeadNext;
        scan(nextComponentHead);
    }
    ListNode* swapPairs(ListNode* head) {
        ListNode* newHead = head;
       if(head != nullptr && head->next != nullptr){
            newHead = head->next;
        }
        scan(head);
        return newHead;
    }
};
