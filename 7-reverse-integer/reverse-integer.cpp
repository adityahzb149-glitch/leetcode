class Solution {
public:
    int reverse(int x) {
        
        long res = 0; // Use long to handle potential overflow
        while (x != 0) {
            int rem = x % 10;
            res = res * 10 + rem;
            x /= 10;
        }
        // Handle 32-bit integer overflow per LeetCode standards
        if (res > INT_MAX || res < INT_MIN) return 0;
        
        return (int)res;    
    }
};