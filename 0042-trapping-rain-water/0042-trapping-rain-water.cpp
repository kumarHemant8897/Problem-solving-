class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> lmax(n), rmax(n);

        int maxi = 0;
        for(int i = 0; i < n; i++){
            maxi = max(height[i], maxi);
            lmax[i] = maxi;
        }

        maxi = 0;
        for(int i = n - 1; i >= 0; i--){
            maxi = max(height[i], maxi);
            rmax[i] = maxi;
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            ans += min(lmax[i], rmax[i]) - height[i];
        }

        return ans;
    }
};