class Solution {
public:
    string removeKdigits(string num, int k) {
      string st;

        for (char digit : num) {

            // remove bigger digits from back
            while (!st.empty() && k > 0 && st.back() > digit) {
                st.pop_back();
                k--;
            }

            st.push_back(digit);
        }

        // if k still remains
        while (k > 0) {
            st.pop_back();
            k--;
        }

        // remove leading zeros
        int i = 0;
        while (i < st.size() && st[i] == '0') {
            i++;
        }

        string ans = st.substr(i);

        return ans.empty() ? "0" : ans;

       

        
    }
};