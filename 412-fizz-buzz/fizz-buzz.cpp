class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;
        unordered_map <int ,string> mp;
        mp[3] = "Fizz";
        mp[5] = "Buzz";

        vector<int> div ;
        div.push_back(3);
        div.push_back(5);

        for (int i = 1; i <= n; i++) {
            string out = "";

            for(int j = 0;j< div.size();j++){
                if(i%div[j]==0){
                    out += mp[div[j]];
                }
            }

            if(out == "") {
                ans.push_back(to_string(i));
            }else {
                ans.push_back(out);
            }
        }
        return ans;
    }
};