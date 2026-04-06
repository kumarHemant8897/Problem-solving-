class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();

        int st=0;
        int end=(n*m)-1;

        while(st<=end){
            int mid=st+(end-st)/2;

           int row=mid/m; // give row convert 1 d to 2d
           int col=mid%m;

            if(mat[row][col]==target){
                return true;
            }
            else if(mat[row][col] <= target){
                st=mid+1;
                
            }
            else{
                end=mid-1;
            }
        }
        return false;
        
    }
};