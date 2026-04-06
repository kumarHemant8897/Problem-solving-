class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> peak;
        int maxi = INT_MIN;
        int row = -1, col = -1;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(mat[i][j] > maxi){
                    maxi = mat[i][j];
                    row = i;
                    col = j;
                }
            }
        }
        
        peak.push_back(row);
        peak.push_back(col);
        
        return peak;
    }
};