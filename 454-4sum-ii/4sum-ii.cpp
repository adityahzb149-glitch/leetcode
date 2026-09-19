class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2,vector<int>& nums3, vector<int>& nums4) {

    unordered_map<int,int> mp; // sum -> freq

    // Step 1: All sums of nums1 + nums2
    for(int a: nums1){
        for(int b: nums2){
            mp[a+b]++;
        }
    }

    // Step 2: Check for complement in nums3 + nums4
    int count = 0;
    for(int c: nums3){
        for(int d: nums4){
            int need = -(c+d);
            if(mp.count(need)){
                count += mp[need];
            }
        }
    }
    return count;
}
};