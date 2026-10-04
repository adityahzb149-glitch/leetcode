
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2)
            return 0;

        vector<bool> isComposite(n, false);

        int count = 1; // Include prime number 2

        for (int i = 3; i <= (n - 1) / i; i += 2) {
            if (isComposite[i])
                continue;

            for (long long j = 1LL * i * i; j < n; j += 2 * i) {
                isComposite[j] = true;
            }
        }

        for (int i = 3; i < n; i += 2) {
            if (!isComposite[i])
                count++;
        }

        return count;
    }
};