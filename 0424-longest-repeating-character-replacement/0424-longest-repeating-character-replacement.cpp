class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int r=0;
        int maxf=0;
        int maxlen=0;
        vector<int> map(26,0);

        while(r<s.size()) {
            map[s[r]-'A']++;
            maxf=max(maxf,map[s[r]-'A']);

            while((r-l+1) -maxf >k){
                map[s[l]-'A']--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);
            r++;

        }
        return maxlen;
        
    }
};