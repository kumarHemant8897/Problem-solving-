class Solution {
public:

    void getallsub(int idx , vector<int> &nums,vector<vector<int>> &ans,vector<int> &sub){
        int n=nums.size();
        if(idx == n){
            ans.push_back(sub);
            return;
        }

        sub.push_back(nums[idx]);
        getallsub(idx+1,nums,ans,sub);
        sub.pop_back();

        getallsub(idx+1,nums,ans,sub);

        
    }


    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> ans;
        vector<int> sub;

        getallsub(0,nums,ans,sub);
        return ans;
        
    }
};