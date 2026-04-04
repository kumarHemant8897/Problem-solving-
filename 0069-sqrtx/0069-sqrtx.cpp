class Solution {
public:
    int mySqrt(int x) {
        long long st = 0, end = x;

        while (st <= end) {
            long long mid = st + (end - st) / 2;

            if (mid * mid <= x) {
                st = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return end; 
    }
};