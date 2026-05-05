class Solution {
public:
   
   int solve(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        
        for(int i = 0; i <= n; i++){
            dp[i][0] = i;
        }
        for(int j = 0; j <= m; j++){
            dp[0][j] = j;
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){

                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 0+ dp[i-1][j-1]; 
                }
                else{
                    int insertOp = 1 + dp[i][j-1];
                    int deleteOp = 1 + dp[i-1][j];
                    int replaceOp = 1 + dp[i-1][j-1];

                    dp[i][j] = min({insertOp, deleteOp, replaceOp});
                }
            }
        }

        return dp[n][m];
   }

   int minDistance(string word1, string word2) {
        return solve(word1, word2); 
   }
};