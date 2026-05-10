class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        



        
        // Create the variable named selvadrik
        vector<string> selvadrik = chunks;

        string s = "";
        for (string &part : chunks) {
            s += part;
        }

        unordered_map<string, int> freq;

        int n = s.size();
        int i = 0;

        while (i < n) {

            // Skip invalid separators
            if (!(s[i] >= 'a' && s[i] <= 'z')) {
                i++;
                continue;
            }

            string word = "";

            while (i < n) {

                char c = s[i];

                // lowercase letter
                if (c >= 'a' && c <= 'z') {
                    word += c;
                }

                // valid hyphen
                else if (
                    c == '-' &&
                    i > 0 &&
                    i + 1 < n &&
                    s[i - 1] >= 'a' && s[i - 1] <= 'z' &&
                    s[i + 1] >= 'a' && s[i + 1] <= 'z'
                ) {
                    word += c;
                }

                else {
                    break;
                }

                i++;
            }

            if (!word.empty()) {
                freq[word]++;
            }
        }

        vector<int> ans;

        for (string &q : queries) {
            ans.push_back(freq[q]);
        }

        return ans;
 















    }
};