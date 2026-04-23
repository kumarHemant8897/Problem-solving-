class Solution {
public:

    bool solve(string &s, int idx, int count,vector<vector<int>> &dp){
        if(count < 0) return false;  
        
        int n = s.size();
        bool ans=false;
        if(idx == n) return count == 0;  

        if(dp[idx][count] !=-1){
            return dp[idx][count];
        }
        
        if(s[idx] == '('){
            ans= solve(s, idx + 1, count + 1,dp);
        }
        else if(s[idx] == ')'){
            ans =solve(s, idx + 1, count - 1,dp);
        }
        else { // '*'
            ans =solve(s, idx + 1, count + 1,dp) ||  
                   solve(s, idx + 1, count - 1,dp) || 
                   solve(s, idx + 1, count,dp);       
        }

         return dp[idx][count]=ans;
    }

    bool checkValidString(string s) {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(s, 0, 0,dp);
    }
};