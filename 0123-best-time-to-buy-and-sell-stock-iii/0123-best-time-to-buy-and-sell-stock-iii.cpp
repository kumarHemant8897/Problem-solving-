class Solution {
public:

   int solve( vector<int>& prices,int idx, int buy, int cap,  vector<vector<vector<int>>> &dp){
    if(idx==prices.size()) return 0;
    if(cap==0) return 0;
    int profit=0;

    if(dp[idx][buy][cap] != -1){
        return dp[idx][buy][cap];
    }

    if(buy){
        dp[idx][buy][cap]=max( -prices[idx] + solve(prices,idx+1,0,cap,dp) , 0+ solve(prices,idx+1,1,cap,dp));
    
    }
    else{
        dp[idx][buy][cap] = max(prices[idx] + solve(prices,idx+1,1,cap-1,dp) , 0 + solve(prices,idx+1,0,cap,dp) );
    }

    return dp[idx][buy][cap];
   }


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>> (2,vector<int>(3,-1)));

        return solve(prices,0,1,2,dp);
        
    }
};