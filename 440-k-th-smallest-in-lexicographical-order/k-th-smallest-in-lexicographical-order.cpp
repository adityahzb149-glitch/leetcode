class Solution {
public:
    long long count(long long curr, long long n) {
        long long steps = 0;
        long long first = curr;
        long long last = curr;

        while (first <= n) {
            steps += min(n + 1, last + 1) - first;
            first *= 10;
            last = last * 10 + 9;
        }

        return steps;
    }

    int findKthNumber(int n, int k) {
        long long curr = 1;
        k--;

        while (k > 0) {
            long long steps = count(curr, n);

            if (steps <= k) {
                curr++;
                k -= steps;
            } else {
                curr *= 10;
                k--;
            }
        }

        return curr;
    }
};