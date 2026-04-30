class Solution {
public:

    bool solve(int idx, int target,vector<int> &nums  , vector<vector<int>> &dp){
        if(target==0) return true;
        if(idx==0) return nums[0]==target;

        if(dp[idx][target] != -1){
            return dp[idx][target];
        }

        bool nottake=solve(idx-1,target,nums,dp);
        bool take=false;

        if(target  >= nums[idx]){
            take=solve(idx-1,target-nums[idx],nums,dp);
        }

        dp[idx][target]= take||nottake;
        return dp[idx][target];

    }





    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum % 2 != 0) return false;

       

        int target=sum/2;
         vector<vector<int>> dp(n,vector<int>(target+1,-1));

        return solve(n-1,target,nums,dp);
        
    }
};