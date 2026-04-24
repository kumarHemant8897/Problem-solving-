class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int> freq(256, 0);

        for(char c : t) {
            freq[c]++;
        }

        int l = 0, r = 0;
        int count = 0;
        int minlen = INT_MAX;
        int stidx = -1;

        while(r < n) {
            if(freq[s[r]] > 0) {
                count++;
            }
            freq[s[r]]--;

            while(count == m) {
                if(r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    stidx = l;
                }

                freq[s[l]]++;
                if(freq[s[l]] > 0) {
                    count--;
                }
                l++;
            }
            r++;
        }

        return stidx == -1 ? "" : s.substr(stidx, minlen);
    }
};