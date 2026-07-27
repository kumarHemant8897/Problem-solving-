class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int first=0;
        int sec=0;

        for(int i=0;i<n;i++){
            if(nums[i] > first){
                sec=first;
                first=nums[i];

            }
            else if(nums[i]>sec){
                sec=nums[i];
            }
        }

        return (first - 1) * (sec-1);
        
    }
};