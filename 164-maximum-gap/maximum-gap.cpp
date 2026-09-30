class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        if (mn == mx) return 0;

        int bucketSize = max(1, (mx - mn) / (n - 1));
        int bucketCount = (mx - mn) / bucketSize + 1;

        vector<pair<int,int>> buckets(bucketCount, {-1,-1}); // {min, max}

        for (int num : nums) {
            int idx = (num - mn) / bucketSize;
            if (buckets[idx].first == -1) {
                buckets[idx] = {num, num};
            } else {
                buckets[idx].first = min(buckets[idx].first, num);
                buckets[idx].second = max(buckets[idx].second, num);
            }
        }

        int maxGap = 0, prevMax = mn;
        for (auto &b : buckets) {
            if (b.first == -1) continue;
            maxGap = max(maxGap, b.first - prevMax);
            prevMax = b.second;
        }
        return maxGap;
    }
};