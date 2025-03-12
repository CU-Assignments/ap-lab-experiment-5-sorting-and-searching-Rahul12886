class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        int start = intervals[0][0];
        int end = intervals[0][1];
        int k = 0;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= end) {
                end = max(intervals[i][1], end);
            } else {
                intervals[k][1] = end;
                end = intervals[i][1];
                k++;
                intervals[k] = intervals[i];
            }
        }
        intervals[k][1] = end;

        intervals.resize(k + 1);
        return intervals;
    }
};



Input: [[1,3],[2,6],[8,10],[15,18]]
  Output: [[1,6],[8,10],[15,18]]
