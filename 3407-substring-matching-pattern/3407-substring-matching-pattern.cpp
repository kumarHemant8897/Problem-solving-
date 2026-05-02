class Solution {
public:
    bool hasMatch(string s, string p) {

        int staridx = p.find('*');

        string prefix = p.substr(0, staridx);
        string suffix = p.substr(staridx + 1);

        int n = s.size();

       
        for(int i = 0; i <= n; i++) {

           
            if(i + prefix.size() <= n &&
               s.substr(i, prefix.size()) == prefix) {

                
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