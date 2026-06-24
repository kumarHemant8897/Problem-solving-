class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_map<char, int> mp;

        for(int i = 0; i < s.size(); i++) {
            if(mp[s[i]] >= 1) {
                return s[i];
            }

            mp[s[i]]++;
        }

        return '\0';
    }
};