class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> mp;
        int count = 0;
    for(char j : jewels) {
        mp[j] = 1; // mark as jewel
    }

    for(char s : stones) {
        if(mp.find(s)!= mp.end()) {
            count++;
        }
    }
    return count;
    }
};