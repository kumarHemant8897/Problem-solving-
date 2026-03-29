class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;
        for(int i = 0; i < n; i++){
            total += nums[i];
        }

        int target = total - x;
        if(target < 0) return -1;
        if(target == 0) return n;

        int left = 0;
        int sum = 0;
        int maxlen = -1;

        for(int r = 0; r < n; r++){
            sum += nums[r];

            while(sum > target){
                sum -= nums[left];
                left++;
            }

            if(sum == target){
                maxlen = max(maxlen, r - left + 1);
            }
        }

        return (maxlen == -1) ? -1 : n - maxlen;
    }
};