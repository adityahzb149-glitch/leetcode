class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         vector<int> result;

    // Merge in sorted order
    merge(nums1.begin(), nums1.end(),
          nums2.begin(), nums2.end(),
          back_inserter(result));

    int n = result.size();

    // Median
    if (n % 2 == 1)
        return result[n / 2];
    else
        return (result[n/2 - 1] + result[n/2]) / 2.0;
    }
};