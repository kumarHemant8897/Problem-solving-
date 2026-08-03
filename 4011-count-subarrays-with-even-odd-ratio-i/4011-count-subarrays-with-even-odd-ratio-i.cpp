class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n=nums.size();
        vector<int> even(n+1,0);
        vector<int> odd(n+1,0);

        for(int i=0;i<n;i++){
            even[i+1]=even[i];
            odd[i+1]=odd[i];
        
        if(nums[i]%2==0){
            even[i+1]++;
        }
        else{
            odd[i+1]++;
        }
        }


        long long ans=0;

       for(int l=0;l<n;l++){
        for(int r=l;r<n;r++){
            int x=even[r+1]-even[l];
            int y=odd[r+1]-odd[l];

            if( y > 0 && 1LL * b * x  <= 1LL* a*y) {
                ans++;
            }
        }
       }

       return ans;
        
    }
};