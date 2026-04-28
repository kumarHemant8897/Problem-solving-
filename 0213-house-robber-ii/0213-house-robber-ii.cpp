class Solution {
public:
  int solve(int i, vector<int> &nums,vector<int> &dp){
    if(i >= nums.size()){
        return 0;
    }

    if(dp[i] != -1){
        return dp[i];
    }

    int take=nums[i]+solve(i+2,nums,dp);

    int nottake=0+solve(i+1,nums,dp);

    dp[i]=max(take,nottake);

    return dp[i];
  }
    int rob(vector<int>& nums) {
        int n=nums.size();

        if(n==1) return nums[0];

        vector<int> temp1;
        vector<int> temp2;

        for(int i=0;i<n;i++){

            if(i!=0) temp1.push_back(nums[i]);
            if( i != n-1) temp2.push_back(nums[i]);
        }

        vector<int> dp1(temp1.size(),-1);
        vector<int> dp2(temp2.size(),-1);


        return max(solve(0,temp1,dp1),solve(0,temp2,dp2));

        
        
    }
};