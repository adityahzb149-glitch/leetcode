
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int counts[3] = {0};

        // Step 1: Count frequency
        for (int num : nums) {
            counts[num]++;
        }

        // Step 2: Overwrite nums
        int index = 0;

        for (int i = 0; i < 3; i++) {
            while (counts[i] > 0) {
                nums[index] = i;
                index++;
                counts[i]--;
            }
        }
    }
};