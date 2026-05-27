class Solution {
public:
    void backtrack(vector<int>& arr, int target, int start, vector<int>& combin, vector<vector<int>>& ans) {
        if (target == 0) {
            ans.push_back(combin);
            return;
        }

        for (int i = start; i < arr.size(); i++) {
            // Skip duplicates
            if (i > start && arr[i] == arr[i-1]) continue;

            if (arr[i] > target) break; // pruning

            combin.push_back(arr[i]);
            backtrack(arr, target - arr[i], i + 1, combin, ans); // move to next index
            combin.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end()); // sort to handle duplicates
        vector<vector<int>> ans;
        vector<int> combin;
        backtrack(arr, target, 0, combin, ans);
        return ans;
    }
};
