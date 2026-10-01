class Solution {
public:
    void countSort(vector<int>& arr, int col) {
        int counts[10] = {0};
        int powVal = 1;
        for (int i = 1; i < col; i++) powVal *= 10; // 10^(col-1)

        for (int i = 0; i < arr.size(); i++) {
            int idx = (arr[i] / powVal) % 10;
            counts[idx]++;
        }

        int startIndex = 0;
        for (int i = 0; i < 10; i++) {
            int curr = counts[i];
            counts[i] = startIndex;
            startIndex += curr;
        }

        int n = arr.size();
        vector<int> sortedArray(n);
        for (int i = 0; i < n; i++) {
            int idx = (arr[i] / powVal) % 10;
            sortedArray[counts[idx]] = arr[i];
            counts[idx]++;
        }

        for (int i = 0; i < n; i++) {
            arr[i] = sortedArray[i];
        }
    }

    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        vector<int> arr = nums;

        int maxG = arr[0];
        for (int num : arr) maxG = max(maxG, num);

        int width = 0;
        if (maxG == 0) width = 1;
        else {
            while (maxG!= 0) {
                maxG /= 10;
                width++;
            }
        }

        for (int i = 1; i <= width; i++) {
            countSort(arr, i);
        }

        int maxN = 0;
        for (int i = 1; i < arr.size(); i++) {
            maxN = max(maxN, arr[i] - arr[i-1]);
        }
        return maxN;
    }
};