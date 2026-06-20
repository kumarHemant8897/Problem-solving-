class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        long long maxi=nums[0];
        long long prefix=0;
        long long suffix=0;
        for(int i=0;i<n;i++){

            if(prefix == 0) prefix=1;
            if(suffix == 0) suffix=1;

            prefix *= nums[i];
            suffix *= nums[n-i-1];

            maxi=max(maxi,max(prefix,suffix));

        }

        return maxi;
        
    }
};