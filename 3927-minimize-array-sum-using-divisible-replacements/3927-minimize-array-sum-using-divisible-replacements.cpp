class Solution {
public:
    long long minArraySum(vector<int>& nums) {

        
       // vector<int> pelnorazi = nums;

        unordered_set<int> st(nums.begin(), nums.end());

        long long sum = 0;

        for (int x : nums) {

            int best = x;

            for (int d = 1; d * d <= x; d++) {

                if (x % d == 0) {

                  
                    if (st.count(d)) {
                        best = min(best, d);
                    }

                   
                    int other = x / d;

                    if (st.count(other)) {
                        best = min(best, other);
                    }
                }
            }

            sum += best;
        }

        return sum;
    }
};