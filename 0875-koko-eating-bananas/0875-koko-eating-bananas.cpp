class Solution {
public:

    long long speed(vector<int> &arr, int hoursly) {
        long long total = 0;
        for (int i = 0; i < arr.size(); i++) {  
            total += ((long long)arr[i] + hoursly - 1) / hoursly;
        }
        return total;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxelem = *max_element(piles.begin(), piles.end());

        int st = 1;
        int end = maxelem;

        while (st <= end) {
            int mid = st + (end - st) / 2;

            long long totalHrs = speed(piles, mid);

            if (totalHrs <= h) {
                end = mid - 1;   // ✅ correct
            } else {
                st = mid + 1;   // ✅ correct
            }
        }

        return st;
    }
};