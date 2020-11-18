class Solution {
public:
    vector<vector<int>> ans;
    int lenM;

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        lenM = nums.size();
        ans.emplace_back(path);

        // if(lenM == 0)
        // {
        //     return ans;
        // }

        //sort(nums.begin(), nums.end());
        backTrack(nums, path, 0);
        return ans;
    }

    void backTrack(vector<int>& nums, vector<int>& path, int startPoint){
        while(startPoint < lenM){ //结束条件
            path.emplace_back(nums[startPoint]);
            ans.emplace_back(path);
            backTrack(nums, path, ++startPoint);
            path.pop_back(); //回退很重要
        }
    }
};
