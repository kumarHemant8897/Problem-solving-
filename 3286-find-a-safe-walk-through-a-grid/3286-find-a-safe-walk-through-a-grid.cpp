class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        queue<tuple<int,int,int>> q;
        vector<vector<int>> best(n, vector<int>(m, -1));

        int sthealth = health - grid[0][0];

        if (sthealth <= 0)
            return false;

        q.push({0, 0, sthealth});
        best[0][0] = sthealth;

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto it = q.front();
            q.pop();

            int row = get<0>(it);
            int col = get<1>(it);
            int h   = get<2>(it);

            if (row == n - 1 && col == m - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m) {
                    int nh = h - grid[nrow][ncol];

                    if (nh > 0 && nh > best[nrow][ncol]) {
                        best[nrow][ncol] = nh;
                        q.push({nrow, ncol, nh});
                    }
                }
            }
        }

        return false;
    }
};