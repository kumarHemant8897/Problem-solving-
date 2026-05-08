class Solution {
public:
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n=land.size();
        int m=land[0].size();
        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(land[i][j]==1) {
                    int r=i;
                    int c=j;

                    while(r+1 < n && land[r+1][j]==1){
                        r++;
                    }

                    while(c+1 < m && land[i][c+1] ==1){
                        c++;
                    }

                    ans.push_back({i,j,r,c});

                    for(int x=i ; x<=r ;x++){
                        for(int y=j ; y<=c;y++){
                            land[x][y]=0;
                        }
                    }
                }
            }
        }

        return ans;
        
    }
};