class Solution {
public:

    vector<int> ans;

    void merge(vector<pair<int,int>>& arr, int low, int mid, int high) {

        vector<pair<int,int>> temp;

        int i = low;
        int j = mid + 1;

        while(i <= mid && j <= high) {

            if(arr[i].first <= arr[j].first) {

                ans[arr[i].second] += (j - (mid + 1));

                temp.push_back(arr[i]);
                i++;
            }
            else {

                temp.push_back(arr[j]);
                j++;
            }
        }

        while(i <= mid) {

            ans[arr[i].second] += (j - (mid + 1));

            temp.push_back(arr[i]);
            i++;
        }

        while(j <= high) {

            temp.push_back(arr[j]);
            j++;
        }

        for(int k = low; k <= high; k++) {
            arr[k] = temp[k - low];
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