class Solution {
public:
    vector<vector<int>> ans;

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> path;
        ans.emplace_back(path);
        sort(nums.begin(), nums.end());

        backTrack(nums, path, 0);
        return ans;    
    }

    void backTrack(vector<int>& nums, vector<int>& path, int startPoint){
        while(startPoint < nums.size()){
            path.emplace_back(nums[startPoint]);
            ans.emplace_back(path);
            backTrack(nums, path, startPoint + 1);
            path.pop_back();
            while( startPoint < nums.size() -1 && nums[startPoint] == nums[startPoint + 1])
                startPoint++;    //同一轮里面，相同元素不多次添加。但是到下一轮的时候不比对前轮次添加的，所以相同元素可以添加
            startPoint++;
        }
    }
};
