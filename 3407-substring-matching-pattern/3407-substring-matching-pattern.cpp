class Solution {
public:
    bool hasMatch(string s, string p) {

        int staridx = p.find('*');

        string prefix = p.substr(0, staridx);
        string suffix = p.substr(staridx + 1);

        int n = s.size();

        // try every starting position
        for(int i = 0; i <= n; i++) {

            // check prefix match
            if(i + prefix.size() <= n &&
               s.substr(i, prefix.size()) == prefix) {

                // check suffix AFTER prefix
                for(int j = i + prefix.size(); j <= n; j++) {

                    if(j + suffix.size() <= n &&
                       s.substr(j, suffix.size()) == suffix) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};