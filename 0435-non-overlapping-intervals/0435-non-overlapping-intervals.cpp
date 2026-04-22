class Solution {
public:
    // comparator function (sort by end time)
    static bool cmp(vector<int> &a, vector<int> &b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0) return 0;

        // sort using comparator
        sort(intervals.begin(), intervals.end(), cmp);

        int count = 1;  // first interval is always taken
        int lastEnd = intervals[0][1];

        for(int i = 1; i < n; i++) {
            // if no overlap
            if(intervals[i][0] >= lastEnd) {
                count++;
                lastEnd = intervals[i][1];
            }
        }

        // remove remaining intervals
        return n - count;
    }
};