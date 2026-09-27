class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> newH = heights;
        sort(newH.begin(),newH.end());
        int count = 0;

        for(int i = 0;i < heights.size();i++){
            if(heights[i] != newH[i])
                count++;

        }

        return count;
    }
};