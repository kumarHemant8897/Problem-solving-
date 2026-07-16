class Solution {
public:
    int GCD(int a , int b){
        while(b){
            int t=a%b;
            a=b;
            b=t;
        }
        return a;
    }


    long long gcdSum(vector<int>& nums) {
        int n=nums.size();

        vector<int> prefixGCD;
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            prefixGCD.push_back(GCD(maxi,nums[i]));
        }

        sort(prefixGCD.begin(),prefixGCD.end());
        int l=0;
        int r=n-1;
        long long ans=0;

        while(l < r){
            ans += GCD(prefixGCD[l] , prefixGCD[r]);
            l++;
            r--;

        }

        return ans;


        
    }
};