class Solution {
public:
    int solve(int k, vector<int>& prices,int idx, int buy, vector<vector<vector<int>>> &dp){
        if(idx==prices.size()){
            return 0;
        }
        if(k==0){
            return 0;
        }
        if(dp[idx][buy][k] != -1){
            return dp[idx][buy][k];
        }
        
        int profit=0;
        if(buy){
            profit= max( -prices[idx]+solve(k,prices,idx+1,0,dp) ,0+ solve(k,prices,idx+1,1,dp));
        }
        else{
            profit = max (prices[idx]+solve(k-1,prices,idx+1,1,dp), 0+ solve(k,prices,idx+1,0,dp));
        }
        return dp[idx][buy][k]= profit;


    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2, vector<int> (k+1,-1)));
        return solve(k,prices,0,1,dp);
        
    }
};