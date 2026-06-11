class Solution {
public:

    int solve(vector<int> &nums,int k){
        int elem=0;
        int part=1;

        for(int i=0;i<nums.size();i++){
            if(nums[i] + elem <= k){
                elem+=nums[i];
            }
            else{
                part++;
                elem=nums[i];
            }
        }

        return part;
    }



    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=0;
        int sum=0;

        for(int i=0;i<n;i++){
            sum+=nums[i];
            maxi=max(maxi,nums[i]);
        }

        int st=maxi;
        int end=sum;
        int ans=0;

        while( st <= end){
            int mid=st+(end-st)/2;

            if(solve(nums,mid) <= k ){
                end= mid-1;

            }
            else{
               st=mid+1;
            }
        }

        return st;
        
    }
};