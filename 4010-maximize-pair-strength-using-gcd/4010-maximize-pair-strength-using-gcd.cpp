class Solution {
public:

    int gcd(int a, int b ){
     while(b != 0){
        int temp=b;
        b=a%b;
        a=temp;
     }
     return a;
    }


    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        long long maxi=LLONG_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long g= gcd(nums[i],nums[j]);
                long long  LCM= 1LL * nums[i] * nums[j] /( g*g);
                maxi=max(maxi,LCM);
            }
        }

        return maxi;


        
    }
};