class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int count=1;
        int longest=1;

        if(n==0) return 0;

        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            if(nums[i] == nums[i-1]+1){
                count++;
            }
            else if(nums[i] != nums[i-1]) {
               count=1;
            }


            longest=max(count,longest);
        }

        return longest;
    }
};