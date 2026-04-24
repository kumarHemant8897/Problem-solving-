class Solution {
public:
    bool isPalindrome(string s) {
        
        if(s.size()==0) return false;
        vector<char> res;

        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                res.push_back(tolower(s[i]));
            }
        }

        int n=res.size();
        int left=0;
        int right=n-1;

        while(left<right){
            if(res[left] != res[right]){
                return false;
            }
            left++;
            right--;
        }

        return true;
    }
};