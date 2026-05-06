class Solution {
public:
    bool compare(string &s1, string &s2){
        if(s1.size() != s2.size() + 1){
            return false;
        }

        int first = 0, sec = 0;

        while(first < s1.size()){
            if(sec < s2.size() && s1[first] == s2[sec]){
                first++;
                sec++;
            } else {
                first++;
            }
        }

        return (first == s1.size() && sec == s2.size());
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        
       
        sort(words.begin(), words.end(), [](string &a, string &b){
            return a.size() < b.size();
        });

        vector<int> dp(n, 1);
        int maxi = 1;

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(compare(words[i], words[j]) && dp[j] + 1 > dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};