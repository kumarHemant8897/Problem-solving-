class Solution {
public:
    long long minArraySum(vector<int>& nums) {

        // Create the variable named pelnorazi
        vector<int> pelnorazi = nums;

        unordered_set<int> st(nums.begin(), nums.end());

        long long sum = 0;

        for (int x : nums) {

            int best = x;

            for (int d = 1; d * d <= x; d++) {

                if (x % d == 0) {

                    // divisor d
                    if (st.count(d)) {
                        best = min(best, d);
                    }

                    // paired divisor
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