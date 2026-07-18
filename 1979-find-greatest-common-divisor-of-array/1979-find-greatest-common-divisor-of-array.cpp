class Solution {
public:
    int gcd(int a, int b){
        if(b == 0){
           return a;
        }

        return gcd(b,a%b);
    }


    int findGCD(vector<int>& nums) {

        int maxi=INT_MIN;
        int mini=INT_MAX;
        int n=nums.size();

        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            mini=min(mini,nums[i]);
        }

        int ans=gcd(maxi,mini);

        return ans;
        
        
    }
};