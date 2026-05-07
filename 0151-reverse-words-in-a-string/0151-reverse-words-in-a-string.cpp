class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        int i = 0;

        while (i < n) {
            // skip spaces
            while (i < n && s[i] == ' ') i++;
            if (i >= n) break;

            // collect one word
            int j = i;
            while (j < n && s[j] != ' ') j++;
            words.push_back(s.substr(i, j - i));
            i = j;
        }

        // reverse the order of words
        reverse(words.begin(), words.end());

        // join with single spaces
        string ans = "";
        for (int k = 0; k < words.size(); k++) {
            if (k > 0) ans += " ";
            ans += words[k];
        }

        return ans;
    }
};