class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        if(len == 0)
            return intervals;

        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        vector<int> tmp = intervals[0];
        for(int i = 1; i < len; i++){
            if(intervals[i][0] <= tmp[1])
                tmp[1] = tmp[1] > intervals[i][1]?tmp[1]:intervals[i][1];
            else{
                ans.emplace_back(tmp);
                tmp = intervals[i];
            }
        }
        ans.emplace_back(tmp);

        return ans;
    }
};
