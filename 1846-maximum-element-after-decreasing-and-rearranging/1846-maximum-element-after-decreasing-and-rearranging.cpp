class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        arr[0]=1;
        for(int i=1;i<n;i++){
            arr[i]=min(arr[i] , arr[i-1]+1);

        }

        int maxi=0;
        return arr.back();
        
        
    }
};