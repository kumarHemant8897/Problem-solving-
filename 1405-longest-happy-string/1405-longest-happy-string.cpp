class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        string ans = "";

        priority_queue<pair<int, char>> pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        while(!pq.empty()) {

            auto first = pq.top();
            pq.pop();

            int len = ans.size();

            
            if(len >= 2 &&
               ans[len-1] == first.second &&
               ans[len-2] == first.second) {

               
                if(pq.empty()) {
                    break;
                }

                auto sec = pq.top();
                pq.pop();

                ans += sec.second;
                sec.first--;

                if(sec.first > 0) {
                    pq.push(sec);
                }

                
                pq.push(first);
            }
            else {

                ans += first.second;
                first.first--;

                if(first.first > 0) {
                    pq.push(first);
                }
            }
        }

        return ans;
    }
};