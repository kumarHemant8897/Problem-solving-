class Solution {
public:
  
    void solve(int idx, string digits, string &output,
               vector<string> &ans, vector<string> &mapping) {
        
        
        if(idx >= digits.size()) {
            ans.push_back(output);
            return;
        }

        int num = digits[idx] - '0';
        string value = mapping[num];

        for(int i = 0; i < value.length(); i++) {

            output.push_back(value[i]);

            solve(idx + 1, digits, output, ans, mapping);

            
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {

        vector<string> ans;

        if(digits.length() == 0) {
            return ans;
        }

        vector<string> mapping(10);

        mapping[2] = "abc";
        mapping[3] = "def";
        mapping[4] = "ghi";
        mapping[5] = "jkl";
        mapping[6] = "mno";
        mapping[7] = "pqrs";
        mapping[8] = "tuv";
        mapping[9] = "wxyz";

        string output = "";

        solve(0, digits, output, ans, mapping);

        return ans;
    }
};