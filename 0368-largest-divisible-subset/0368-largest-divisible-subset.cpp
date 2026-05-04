class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin(), nums.end()); 
        
        vector<int> dp(n, 1);
        vector<int> parent(n);
        
        for(int i = 0; i < n; i++) {
            parent[i] = i;
            for(int prev = 0; prev < i; prev++) {
                if(nums[i] % nums[prev] == 0 && dp[i] < 1 + dp[prev]) {
                    dp[i] = 1 + dp[prev];
                    parent[i] = prev;
                }
            }
        }
        
        int maxi = 0, lastIndex = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] > maxi) {
                maxi = dp[i];
                lastIndex = i;
            }
        }
        
       
        vector<int> ans;
        while(parent[lastIndex] != lastIndex) {
            ans.push_back(nums[lastIndex]);
            lastIndex = parent[lastIndex];
        }
        ans.push_back(nums[lastIndex]);
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};