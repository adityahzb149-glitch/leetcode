class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = INT_MIN;
        int maxRange = 0;
        int currRange = 0;

        for(int i = 0;i < nums.size();i++){
            if(nums[i]>maxVal){
                maxVal = nums[i];
                maxRange = 1;
                currRange = 1;
            }else if(nums[i] == maxVal){
                currRange++;
            }else{
                currRange = 0;
            }

            maxRange = max(maxRange,currRange);
        }

        return maxRange;
    }
};