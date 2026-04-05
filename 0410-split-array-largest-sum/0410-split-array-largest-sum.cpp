class Solution {
public:

 int solve(vector<int> &arr , int k){
    int part=1;
    int elem=0;

    for(int i=0;i<arr.size();i++){
        if(arr[i] + elem > k){
            part++;
            elem=arr[i];
           
        }
        else{
       
        elem+=arr[i];
        }
             
    }

    return part;
 }

    int splitArray(vector<int>& nums, int k) {
       int n=nums.size();
       int sum=0;
       int maxi=0;

       for(int i=0;i<n;i++){
        sum+=nums[i];
        maxi=max(maxi,nums[i]);
       }
       
       int st=maxi;
       int end=sum;

       while(st<=end){
        int mid=st+(end-st)/2;

        if(solve(nums,mid) <= k){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
       }
       return st;
        
    }
};