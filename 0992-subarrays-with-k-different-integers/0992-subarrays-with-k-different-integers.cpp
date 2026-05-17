class Solution {
public:
   int solve(vector<int>& nums, int k){
    int r=0;
    int l=0;
    int count=0;
    unordered_map<int,int> freq;
    while(r<nums.size()){
        freq[nums[r]]++;

        while(freq.size()>k){
            freq[nums[l]]--;

            if(freq[nums[l]]==0){
                freq.erase(nums[l]);
            }
               
              l++;
        }
         count+=(r-l+1);
        r++;
    }
    return count;
   }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums,k) - solve(nums,k-1);
        
    }
};