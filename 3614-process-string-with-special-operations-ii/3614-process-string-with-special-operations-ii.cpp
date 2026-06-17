class Solution {
public:
    char processStr(string s, long long k) {
        const long long LIM = 1e15 + 1;
        int n = s.size();

        vector<long long> len(n);
        long long cur = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (islower(ch)) {
                cur++;
            }
            else if (ch == '*') {
                if (cur > 0) cur--;
            }
            else if (ch == '#') {
                cur = min(LIM, cur * 2);
            }
            else {
                
            }

            len[i] = cur;
        }

        if (k >= cur) return '.';

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            long long prev = (i == 0 ? 0 : len[i - 1]);

            if (islower(ch)) {
                if (k == prev) return ch;
            }
            else if (ch == '#') {
                if (prev > 0) k %= prev;
            }
            else if (ch == '%') {
                if (len[i] > 0)
                    k = len[i] - 1 - k;
            }
            else { 
               
               
            }
        }

        return '.';
    }
};