class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> ans;

        for (int i = 0; i < expression.size(); i++) {
            char op = expression[i];

            if (op == '+' || op == '-' || op == '*') {
                vector<int> left =
                    diffWaysToCompute(expression.substr(0, i));

                vector<int> right =
                    diffWaysToCompute(expression.substr(i + 1));

                for (int a : left) {
                    for (int b : right) {
                        if (op == '+')
                            ans.push_back(a + b);
                        else if (op == '-')
                            ans.push_back(a - b);
                        else
                            ans.push_back(a * b);
                    }
                }
            }
        }

        // Base case
        if (ans.empty())
            ans.push_back(stoi(expression));

        return ans;
    }
};