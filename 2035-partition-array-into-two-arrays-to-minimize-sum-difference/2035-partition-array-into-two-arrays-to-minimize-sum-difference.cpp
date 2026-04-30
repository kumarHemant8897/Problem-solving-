class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size() / 2;

        vector<vector<int>> left(n + 1), right(n + 1);

        // Split into two halves
        for(int mask = 0; mask < (1 << n); mask++){
            int lsum = 0, rsum = 0, cnt = 0;

            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    lsum += nums[i];
                    rsum += nums[i + n];
                    cnt++;
                }
            }

            left[cnt].push_back(lsum);
            right[cnt].push_back(rsum);
        }

        for(int i = 0; i <= n; i++){
            sort(right[i].begin(), right[i].end());
        }

        int total = accumulate(nums.begin(), nums.end(), 0);
        int ans = INT_MAX;

        for(int lcnt = 0; lcnt <= n; lcnt++){
            for(int lsum : left[lcnt]){

                int rcnt = n - lcnt;
                int target = total / 2 - lsum;

                auto &vec = right[rcnt];

                auto it = lower_bound(vec.begin(), vec.end(), target);

                if(it != vec.end()){
                    int s1 = lsum + *it;
                    int s2 = total - s1;
                    ans = min(ans, abs(s1 - s2));
                }

                if(it != vec.begin()){
                    --it;
                    int s1 = lsum + *it;
                    int s2 = total - s1;
                    ans = min(ans, abs(s1 - s2));
                }
            }
        }

        return ans;
    }
};