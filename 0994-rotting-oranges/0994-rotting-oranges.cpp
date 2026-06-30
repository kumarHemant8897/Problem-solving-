class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>> q;

        int fresh = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        int time = 0;
        int cnt = 0;

        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int tm  = q.front().second;
            q.pop();

            time = max(time, tm);

            for(int i=0;i<4;i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow>=0 && nrow<n &&
                   ncol>=0 && ncol<m &&
                   vis[nrow][ncol]==0 &&
                   grid[nrow][ncol]==1){

                    vis[nrow][ncol] = 1;
                    cnt++;

                    q.push({{nrow,ncol}, tm+1});
                }
            }
        }

       if(cnt != fresh) return -1;

        return time;
    }
};