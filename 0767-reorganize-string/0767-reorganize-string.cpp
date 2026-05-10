class Solution {
public:
    string reorganizeString(string s) {

        int n = s.size();

        vector<int> freq(26, 0);

        
        for(int i = 0; i < n; i++) {
            freq[s[i] - 'a']++;
        }

        int maxi = 0;
        char maxchar;

        
        for(int i = 0; i < 26; i++) {

            if(freq[i] > maxi) {
                maxi = freq[i];
                maxchar = i + 'a';
            }
        }

        
        if(maxi > (n + 1) / 2) {
            return "";
        }

        string ans(n, ' ');

        int idx = 0;

       
        while(freq[maxchar - 'a'] > 0) {

            ans[idx] = maxchar;
            idx += 2;

            freq[maxchar - 'a']--;
        }

       
        for(int i = 0; i < 26; i++) {

            while(freq[i] > 0) {

                if(idx >= n) {
                    idx = 1;
                }

                ans[idx] = i + 'a';
                idx += 2;

                freq[i]--;
            }
        }

        return ans;
    }
};