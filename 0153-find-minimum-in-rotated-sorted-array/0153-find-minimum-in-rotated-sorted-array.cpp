class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        int ans=nums[0];

        while(st <= end){
            int mid = st + (end - st)/2;

            if(nums[st] <= nums[mid]){
                ans=min(ans,nums[st]);
                st=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                end=mid-1;

            }
        }

        return ans;
        
    }
};