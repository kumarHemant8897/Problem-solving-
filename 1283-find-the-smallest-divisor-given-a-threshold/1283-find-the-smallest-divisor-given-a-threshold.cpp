class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
        }

        int st=1;
        int end=maxi;

        while(st<=end){
            int mid=st+(end-st)/2;
            int sum=0;

            for(int i=0;i<n;i++){
                sum+=(nums[i] + mid -1 ) / mid;
            }

            if(sum <= threshold ){
                end=mid - 1;
            }
            else{
                st=mid+1;
            }
        }

        return st;
        
    }
};