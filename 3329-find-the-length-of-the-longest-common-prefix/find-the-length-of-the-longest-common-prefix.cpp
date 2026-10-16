class TrieNode {
public:
    TrieNode* children[10];

    TrieNode() {
        for (int i = 0; i < 10; i++) {
            children[i] = nullptr;
        }
    }
};

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        TrieNode* root = new TrieNode();

        // Insert all numbers from arr1 into Trie
        for (int num : arr1) {
            TrieNode* node = root;
            string s = to_string(num);

            for (char c : s) {
                int digit = c - '0';

                if (node->children[digit] == nullptr) {
                    node->children[digit] = new TrieNode();
                }

                node = node->children[digit];
            }
        }

        // Search numbers from arr2
        int maxi = 0;

        for (int num : arr2) {
            TrieNode* node = root;
            string s = to_string(num);
            int len = 0;

            for (char c : s) {
                int digit = c - '0';

                if (node->children[digit] == nullptr) {
                    break;
                }

                node = node->children[digit];
                len++;
            }

            maxi = max(maxi, len);
        }

        return maxi;
    }
};