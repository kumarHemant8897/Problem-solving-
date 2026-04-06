class Solution {
public:

  bool bs(vector<int> &arr, int target){
    int n=arr.size();
    int st=0;
    int end=n-1;

    while(st<=end){
        int mid=st+(end-st)/2;

        if(arr[mid]==target){
            return true;
        }

       else if(arr[mid] < target){
            st=mid+1;
        }
        else{
            end=mid-1;

        }
    }
    return false;
  }



    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int n=mat.size();
        int m=mat[0].size();

        for(int i=0;i<n;i++){
            if(bs(mat[i],target)==true){
                return true;
                
            }
           
        }
        return false;


        
    }
};