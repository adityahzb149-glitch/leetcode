class Solution {
public:

    void reverse(string& arr, int start, int end) {
        while (start < end) {
            char temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;

            start++;
            end--;
        }
    }

    string reverseWords(string s) {

        int start = 0;
        int end = 0;

        while (start < s.size()) {

            while (end < s.size() && s[end] != ' ') {
                end++;
            }

            reverse(s, start, end - 1);

            start = end + 1;
            end = start;
        }

        return s;
    }
};