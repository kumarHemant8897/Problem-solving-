class Solution {
public:

  int solve(string text1, int idx1 , string text2, int idx2, vector<vector<int>> &dp){
    if(idx1 < 0 || idx2 < 0){
        return 0;
    }

    if(dp[idx1][idx2] != -1){
        return dp[idx1][idx2];
    }

    if(text1[idx1] == text2[idx2]){
        return 1 +  solve(text1,idx1-1, text2,idx2-1,dp);
    }
    else{
        return 0 + max(solve(text1,idx1-1,text2,idx2,dp) , solve(text1,idx1,text2,idx2-1,dp));

    }
  }


    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

       for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(text1[i-1] == text2[j-1]){
                dp[i][j]= 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j]= 0 + max(dp[i-1][j] , dp[i][j-1]);
            }
        }
       }

       return dp[n][m];
        
    }
};