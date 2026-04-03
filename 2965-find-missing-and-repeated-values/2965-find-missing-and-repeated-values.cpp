class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        unordered_map<int,int> mp;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mp[grid[i][j]]++;
            }
        }

        int rep=1;
        int mis=1;

        for(int i=1;i<=n*m;i++){
            if(mp[i]==0) mis=i;
            if(mp[i] >1) rep=i;
        }

        return {rep,mis};
        
    }
};