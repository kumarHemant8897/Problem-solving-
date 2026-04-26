class Solution {
public:
    int maximumPossibleSize(vector<int>& nums) {
        vector<int> st;

        for (int x : nums) {
            while (!st.empty() && st.back() > x) {
                x = max(x, st.back());
                st.pop_back();  // ✅ FIX HERE
            }
            st.push_back(x);
        }

        return st.size();
    }
};