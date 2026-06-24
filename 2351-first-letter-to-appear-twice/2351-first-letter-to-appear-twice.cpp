class Solution {
public:
    char repeatedCharacter(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(s[i] == s[j]){
                   return s[i];          
                }
            }
        }
        return {-1};
        
    }
};