class Solution {
public:
  int solve(vector<int>& nums, int k){
    int n=nums.size();
    int l=0;
    int r=0;
    int sum=0;
    int count=0;

    while(r<n){
        sum+=nums[r]%2;

        while(sum > k ){
            sum-=nums[l]%2;
            l++;
        }
        count=count+(r-l+1);
        r++;

    }
    return count;
  }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
        
    }
};