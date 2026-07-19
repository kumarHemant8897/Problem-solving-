class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();

        vector<int> last(26);
        vector<int> vis(26, 0);

        for (int i = 0; i < n; i++)
            last[s[i] - 'a'] = i;

        string ans;

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (vis[c - 'a'])
                continue;

            while (!ans.empty() &&
                   ans.back() > c &&
                   last[ans.back() - 'a'] > i) {
                vis[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            ans.push_back(c);
            vis[c - 'a'] = 1;
        }

        return ans;
    }
};