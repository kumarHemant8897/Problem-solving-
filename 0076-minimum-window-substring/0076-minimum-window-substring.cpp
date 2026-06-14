class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> freq(256, 0);

        for(char c : t)
            freq[c]++;

        int l = 0;
        int start = 0;
        int minLen = INT_MAX;
        int required = t.size();

        for(int r = 0; r < s.size(); r++) {

            if(freq[s[r]] > 0)
                required--;

            freq[s[r]]--;

            while(required == 0) {

                if(r - l + 1 < minLen) {
                    minLen = r - l + 1;
                    start = l;
                }

                freq[s[l]]++;

                if(freq[s[l]] > 0)
                    required++;

                l++;
            }
        }

        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};