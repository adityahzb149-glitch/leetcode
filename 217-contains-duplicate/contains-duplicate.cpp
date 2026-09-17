// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         sort(nums.begin(),nums.end());

//         for(int i =0 ;i<nums.size()-1;i++){
//             if(nums[i]==nums[i+1]){
//             return true;
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::unordered_set<int> seen;
        
        for (int num : nums) {
            if (seen.count(num) > 0) {
                return true;
            }
            seen.insert(num);
        }
        
        return false;
    }
};