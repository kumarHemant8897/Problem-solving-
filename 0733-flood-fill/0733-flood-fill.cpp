class Solution {
public:

    void dfs(int row, int col, vector<vector<int>> &image,
             int newcolor, int inicolor,
             int delrow[], int delcol[],
             vector<vector<int>> &ans) {

        ans[row][col] = newcolor;

        int n = image.size();
        int m = image[0].size();

        for (int i = 0; i < 4; i++) {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if (nrow >= 0 && nrow < n &&
                ncol >= 0 && ncol < m &&
                image[nrow][ncol] == inicolor &&
                ans[nrow][ncol] != newcolor) {

                dfs(nrow, ncol, image, newcolor,
                    inicolor, delrow, delcol, ans);
            }
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                  int sr, int sc, int color) {

        vector<vector<int>> ans = image;
        int inicolor = image[sr][sc];

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};

        dfs(sr, sc, image, color, inicolor,
            delrow, delcol, ans);

        return ans;
    }
};