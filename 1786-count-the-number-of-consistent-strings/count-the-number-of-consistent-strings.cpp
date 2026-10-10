class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        set<char> s;

        for (char c : allowed) {
            s.insert(c);
        }

        int count = 0;

        for (string word : words) {
            bool isConsistent = true;

            for (char c : word) {
                if (s.find(c) == s.end()) {
                    isConsistent = false;
                    break;
                }
            }

            if (isConsistent) {
                count++;
            }
        }

        return count;
    }
};