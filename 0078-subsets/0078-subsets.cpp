class Solution {
public:

   void getallsub(int idx,vector<int> &nums,vector<int> &sub, vector<vector<int>> &ans){
        int n=nums.size();
        if(idx==n){
            ans.push_back(sub);
            return;
        }

        sub.push_back(nums[idx]);
        getallsub(idx+1,nums,sub,ans);
        sub.pop_back();

        getallsub(idx+1,nums,sub,ans);
   }


    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> sub;

        getallsub(0,nums,sub,ans);
        return ans;
        
    }
};