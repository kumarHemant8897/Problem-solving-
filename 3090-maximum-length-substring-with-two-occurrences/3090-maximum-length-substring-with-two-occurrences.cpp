class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
         unordered_map<char, int> mp;

        int ans=0;
        int l=0;

        for(int r=0;r<n;r++){
            mp[s[r]]++;


            while(mp[s[r]] > 2){
                mp[s[l]]--;
                l++;
            }

            ans=max(ans,r - l +1);
        }

        return ans;
        
    }
};