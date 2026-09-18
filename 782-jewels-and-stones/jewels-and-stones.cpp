class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> set;
    for(char j : jewels) {
        set.insert(j);
    }

    int count = 0;
    for(char s : stones) {
        if(set.find(s)!= set.end()) {
            count++;
        }
    }
    return count;

    }
};