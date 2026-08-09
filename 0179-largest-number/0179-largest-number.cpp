class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> arr;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            arr.push_back(to_string(nums[i]));
        }

        sort(arr.begin(), arr.end(), [](string a, string b) {
            return a + b > b + a;
        });

        if (arr[0] == "0") {
            return "0";
        }

        string ans = "";

        for (string s : arr) {
            ans += s;
        }

        return ans;
    }
};