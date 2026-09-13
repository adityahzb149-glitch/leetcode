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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }

        int size = 0;
        ListNode* tail = nullptr;
        ListNode* curr = head;

        while(curr != nullptr){
            tail = curr;
            curr = curr->next;
            size++;
        }

        int newK = k % size;
        if(newK == 0){
            return head;
        }
        int diff = size - newK;

        curr = head;
        // int i = 0;

        for(int i = 0;i < diff - 1;i++){
            curr = curr->next;
            
        }

        ListNode* newHead = curr->next;
        curr->next = nullptr;
        tail->next = head;

        return newHead;
    }
};