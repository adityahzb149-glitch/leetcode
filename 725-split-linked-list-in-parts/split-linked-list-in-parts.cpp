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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k, nullptr);

        int count = 0;

        ListNode* curr = head;

        while(curr != nullptr){
            count++;
            curr = curr->next;
        }

        int minEle = count/k;
        int remain = count - (minEle*k);

        curr = head;

        for(int i = 0;i < k;i++){
            ans[i] = curr;

            int partSize = minEle + (i < remain ? 1 : 0);

            for (int j = 1; j < partSize && curr; j++) {
                curr = curr->next;
            }

            if (curr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }
        }

        return ans;
    }
};