class Solution {
public:

    vector<int> nse(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                ans[i] = n;
            }
            else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    vector<int> pse(vector<int>& arr) {

        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if(st.empty()) {
                ans[i] = -1;
            }
            else {
                ans[i] = st.top();
            }

            st.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        vector<int> next = nse(heights);
        vector<int> prev = pse(heights);

        int maxi = 0;

        for(int i = 0; i < n; i++) {

            int width = next[i] - prev[i] - 1;
            int area = heights[i] * width;

            maxi = max(maxi, area);
        }

        return maxi;
    }
};