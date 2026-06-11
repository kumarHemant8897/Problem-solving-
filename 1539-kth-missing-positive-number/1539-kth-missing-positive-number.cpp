class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        unordered_set<int> st;

        for (int i = 0; i < arr.size(); i++) {
            st.insert(arr[i]);
        }

        vector<int> ans;

        int num = 1;

        while (ans.size() < k) {
            if (st.find(num) == st.end()) {
                ans.push_back(num);
            }
            num++;
        }

        return ans[k - 1];
    }
};