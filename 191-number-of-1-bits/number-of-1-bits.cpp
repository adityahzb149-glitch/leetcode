class Solution {
public:
    long long factorial(int n) {
        long long fact = 1;

        for (int i = 1; i <= n; i++)
            fact *= i;

        return fact;
    }

    long long combination(int n, int r) {
        return factorial(n) /
               (factorial(r) * factorial(n - r));
    }

    int hammingWeight(int n) {
        bitset<32> bits(n);
        return bits.count();
    }
};
