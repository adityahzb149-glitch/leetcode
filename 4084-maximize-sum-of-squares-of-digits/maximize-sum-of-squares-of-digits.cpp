class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (num <= 0 || sum < 0 || sum > 9 * num)
            return "";

        string result;
        result.reserve(num);

        while (sum >= 9) {
            result += '9';
            sum -= 9;
        }

        if (result.size() < num && sum > 0) {
            result += char('0' + sum);
        }

        while (result.size() < num) {
            result += '0';
        }

        return result;
    }
};