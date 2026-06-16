class Solution {
public:

   int solve(int idx, vector<int> &nums, vector<int> &dp){
    if(idx >= nums.size()) return 0;

    if(dp[idx] != -1){
        return dp[idx];
    }

    int take= nums[idx] + solve(idx+2,nums,dp);
    int notake= solve(idx+1,nums,dp);

    dp[idx]=max(take , notake);
    return dp[idx];
   }


    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int> temp1;
        vector<int> temp2;
        for(int i=0;i<n;i++){
            if(i != 0) temp1.push_back(nums[i]);
            if( i != n-1) temp2.push_back(nums[i]);
        }

        vector<int> dp1(temp2.size() , -1);
        vector<int> dp2(temp2.size() ,-1);

        int ans=max(solve(0,temp1,dp1) , solve(0,temp2,dp2));
        return ans;

        
    }
};