class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();
        int m=matrix[0].size();

        int row=0;
        int coll=m-1;

        while(row < n && coll >=0){
            if(matrix[row][coll] == target){
                return true;
            }
            if(matrix[row][coll] < target){
                row++;
            }
            else{
                coll--;
            }
        }

        return false;

        
    }
};