class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> ans;

       
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                ans.push_back(grid[i][j]);
            }
        }

        
        int rem = ans[0] % x;
        for(int num : ans){
            if(num % x != rem) return -1;
        }

        
        sort(ans.begin(), ans.end());

        int size = ans.size();

        
        int median = ans[size / 2];

        
        int ops = 0;
        for(int i = 0; i < size; i++){
            ops += abs(ans[i] - median) / x;
        }

        return ops;
    }
};