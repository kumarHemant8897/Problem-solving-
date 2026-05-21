class Solution {
public:

    void merge(vector<pair<int,int>>& arr, int low, int mid,
               int high, vector<int>& ans) {

        vector<pair<int,int>> temp;

        int left = low;
        int right = mid + 1;

        int cnt = 0;

        while(left <= mid && right <= high) {

            if(arr[right].first < arr[left].first) {

                cnt++;
                temp.push_back(arr[right]);
                right++;
            }
            else {

                ans[arr[left].second] += cnt;
                temp.push_back(arr[left]);
                left++;
            }
        }

        while(left <= mid) {

            ans[arr[left].second] += cnt;
            temp.push_back(arr[left]);
            left++;
        }

        while(right <= high) {

            temp.push_back(arr[right]);
            right++;
        }

        for(int i = low; i <= high; i++) {
            arr[i] = temp[i - low];
        }
    }

    void mergeSort(vector<pair<int,int>>& arr, int low,
                   int high, vector<int>& ans) {

        if(low >= high) return;

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid, ans);
        mergeSort(arr, mid + 1, high, ans);

        merge(arr, low, mid, high, ans);
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        vector<pair<int,int>> arr;
        vector<int> ans(n, 0);

        for(int i = 0; i < n; i++) {
            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1, ans);

        return ans;
    }
};