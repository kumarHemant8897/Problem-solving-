class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);

        int element = 1;
        int i = 0;

        if (n % 2 != 0) {
            ans[0] = 0;
            i = 1;
        }

        while (i < n) {
            ans[i] = element;
            ans[i + 1] = -element;
            element++;
            i += 2;
        }

        return ans;
    }
};