class Solution {
public:
   int solve( int idx, string s,unordered_set<string> &st , vector<int> &dp){
    int n=s.size();
    if(idx >=n){
        return 0;
    }

    if(dp[idx] != -1){
        return dp[idx];
    }

    int ans= 1 + solve(idx+1,s,st,dp);
    string temp="";
    for(int j=idx;j<=n;j++){
         temp+=s[j];

         if(st.count(temp)){
             ans=min(ans,solve(j+1,s,st,dp));
         }
    }

    return dp[idx]=ans;




   }

    int minExtraChar(string s, vector<string>& dictionary) {
        int n=s.size();

        unordered_set<string> st(dictionary.begin(),dictionary.end());
        vector<int> dp(n,-1);

        return solve(0,s,st,dp);

        
    }
};