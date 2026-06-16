class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());

        long long reach = 0;
        int i = 0;
        int added = 0;
        int n = coins.size();

        while (reach < target) {
            if (i < n && coins[i] <= reach + 1) {
                reach += coins[i];
                i++;
            } else {
                reach += (reach + 1);
                added++;
            }
        }

        return added;
    }
};