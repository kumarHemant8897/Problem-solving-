class Solution {
public:
    string reorganizeString(string s) {

        unordered_map<char, int> mp;
        int n = s.size();

        
        for(int i = 0; i < n; i++) {
            mp[s[i]]++;
        }

        
        for(auto it : mp) {
            if(it.second > (n + 1) / 2) {
                return "";
            }
        }

        
        priority_queue<pair<int, char>> pq;

        for(auto it : mp) {
            pq.push({it.second, it.first});
        }

        string ans = "";

        while(pq.size() >= 2) {

            auto first = pq.top();
            pq.pop();

            auto sec = pq.top();
            pq.pop();

            ans += first.second;
            ans += sec.second;

            first.first--;
            sec.first--;

            if(first.first > 0) {
                pq.push(first);
            }

            if(sec.first > 0) {
                pq.push(sec);
            }
        }

        
        if(!pq.empty()) {
            ans += pq.top().second;
        }

        return ans;
    }
};