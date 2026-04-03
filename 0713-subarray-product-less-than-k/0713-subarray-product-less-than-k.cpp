class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;

        int count = 0;
        int n = nums.size();
        int r = 0;
        int l = 0;
        long long pro = 1;

        while(r < n){
            pro *= nums[r];

            while(pro >= k){
                pro =pro/ nums[l];
                l++;
            }

            count += (r - l + 1);
            r++;   
        }
        return count;
    }
};