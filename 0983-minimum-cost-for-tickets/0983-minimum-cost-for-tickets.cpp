class Solution {
public:
   int solve(int idx, vector<int> &days, vector<int> &costs,vector<int> &dp){
    int n=days.size();
    if(idx >= n) return 0;

    if(dp[idx] != -1){
        return dp[idx];
    }

    int cost1= costs[0] + solve(idx+1,days,costs,dp);
    int cost7=0;
    int cost30=0;

    int j=idx;

    while(j<n && days[j] < days[idx]+7){
        j++;
    }
    cost7= costs[1] + solve(j,days,costs,dp);



    j=idx;
    while(j<n && days[j] < days[idx]+30){
        j++;
    }
    cost30 = costs[2] +  solve(j,days,costs,dp);

    dp[idx]= min({cost1, cost7, cost30});
    return dp[idx];




   }




    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n,-1);
        return solve(0,days,costs,dp);
        
        
    }
};