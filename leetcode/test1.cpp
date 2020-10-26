class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //solution 1
        // vector<int> res;
        // int len = nums.size();
        // for(int i = 0; i < len; i++){
        //     for(int j = i+1; j < len; j++){
        //         if(nums[i] + nums[j] == target){
        //             res.push_back(i);
        //             res.push_back(j);
        //             return res;
        //         }
        //     }
        // }
        // return res;

        //solution2
        vector<int> res;
        vector<int> cp = nums;
        sort(cp.begin(), cp.end());
        int left = 0;
        int right = cp.size() - 1;
        while(left< right){
            int sum = cp[left] + cp[right];
            if(sum == target)
            {
                int lIndex = find(nums.begin(), nums.end(), cp[left]) - nums.begin();
                nums[lIndex] = INT_MAX;
                int rIndex = find(nums.begin(), nums.end(), cp[right]) - nums.begin();
                res.push_back(lIndex);
                res.push_back(rIndex);
                break;
                
            }
            else if(sum < target)
                left++;
            else
                right--;
        
        }
        return res;
    }
};
