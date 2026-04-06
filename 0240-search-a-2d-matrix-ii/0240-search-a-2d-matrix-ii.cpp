class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();

        int row=0;
        int coll=m-1;

        while(row<n && coll>=0){
            if(mat[row][coll]==target){
               return true;
            }
            else if(mat[row][coll] < target){
                row++;
            }
            else{
                coll--;
            }
        }
        return false;

        
    }
};