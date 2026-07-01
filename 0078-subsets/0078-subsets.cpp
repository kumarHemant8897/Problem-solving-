class Solution {
public:

  void solve(int idx, vector<int> &nums,vector<vector<int>> &ans,vector<int> &sub){
    if(idx == nums.size()){
        ans.push_back(sub);
        return;
    }
    sub.push_back(nums[idx]);
    solve(idx+1,nums,ans,sub);
    sub.pop_back();

    solve(idx+1,nums,ans,sub);
  }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> sub;

        solve(0,nums,ans,sub);
        return ans;
        
    }
};