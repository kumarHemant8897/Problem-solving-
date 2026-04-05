class Solution {
public:

    long long solve(vector<int> &arr, int candies){
        long long child = 0;  

        for(int i = 0; i < arr.size(); i++){  
            child += arr[i] / candies;
        }
        return child;
    }

    int maximumCandies(vector<int>& can, long long k) {
        int maxi = 0;

        for(int i = 0; i < can.size(); i++){
            maxi = max(maxi, can[i]);
        }

        int st = 1;
        int end = maxi;
        int ans=0;

        while(st <= end){
            int mid = st + (end - st) / 2;

            if(solve(can, mid) >= k){
                st = mid + 1;
                ans=mid;
            }
            else{
                end = mid - 1;
            }
        }

        return ans;
    }
};