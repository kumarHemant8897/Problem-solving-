class Solution {
public:
    bool poss(vector<int>& arr, int day, int m, int k) {
        int count = 0, bouquets = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            } else {
                count = 0;
            }
        }
        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long total= 1LL * m * k;
        if (n < total) return -1;

        int st = 1, end = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (poss(bloomDay, mid, m, k)) {
                ans = mid;
                end = mid - 1;  
            } else {
                st = mid + 1;   
            } 
        }
        return ans;
    }
};
