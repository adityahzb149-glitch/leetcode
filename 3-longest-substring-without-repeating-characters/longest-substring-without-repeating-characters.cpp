class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int charMap[128];
        fill(charMap, charMap + 128, -1);
        
        int maxLen = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); ++end) {
            if (charMap[s[end]] >= start) {
                start = charMap[s[end]] + 1;
            }
            
            charMap[s[end]] = end;
            maxLen = max(maxLen, end - start + 1);
        }
        
        return maxLen;
    }
};