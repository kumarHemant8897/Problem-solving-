class Solution {
public:
    int solve(int i, int j,vector<int> &cuts,vector<vector<int>> &dp){

        if(i > j ) return 0;

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        int mini=INT_MAX;
        for(int idx=i;idx<=j;idx++){
            int ans= cuts[j+1]- cuts[i-1] + solve(i,idx-1,cuts,dp) + solve(idx+1,j,cuts,dp);

            mini=min(ans,mini);
        }

        return dp[i][j] =mini;

    }


    int minCost(int n, vector<int>& cuts) {
        int N=cuts.size();

        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());

        vector<vector<int>> dp(N+2,vector<int>(N+1,-1));
        return solve(1,N,cuts,dp);
        
    }
};