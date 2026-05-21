class Solution {
public:

    vector<int> ans;

    void merge(vector<pair<int,int>>& arr, int low, int mid, int high) {

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

    void mergeSort(vector<pair<int,int>>& arr, int low, int high) {

        if(low >= high) return;

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);

        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }

    vector<int> countSmaller(vector<int>& nums) {

        int n = nums.size();

        ans.resize(n, 0);

        vector<pair<int,int>> arr;

        for(int i = 0; i < n; i++) {

            arr.push_back({nums[i], i});
        }

        mergeSort(arr, 0, n - 1);

        return ans;
    }
};