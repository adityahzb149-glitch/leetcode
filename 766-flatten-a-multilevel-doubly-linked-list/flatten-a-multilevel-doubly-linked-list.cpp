/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head == nullptr){
            return head;
        }

        stack<Node*> st;
        st.push(head);

        Node* prev = nullptr;

        while(!st.empty()){
            Node* curr = st.top();
            st.pop();

            if (prev != nullptr) {
                prev->next = curr;
                curr->prev = prev;
            }

            if (curr->next != nullptr) {
                st.push(curr->next);
            }
            if (curr->child != nullptr) {
                st.push(curr->child);
                curr->child = nullptr;
            }

            prev = curr;
        }

        return head;

    }
};