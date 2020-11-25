class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //solution 1
        // if(nums.size() == 0)
        //     return 0;
        // if(target <= nums[0])
        //     return 0;
        // for(int i = 0; i < nums.size(); i++){
        //     if(target == nums[i])
        //         return i;
        //     if(i + 1 < nums.size() && nums[i] < target && nums[i + 1] > target)
        //         return i + 1;
        // }
        // return nums.size();

        //solution2
        int ans = nums.size();
        int mid;
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            mid = (right + left)/2; //(right - left)/2 + left

            if(target <= nums[mid]){
                right = mid - 1;
                ans = mid;
            }
            else if(target > nums[mid])
                left = mid + 1;
        }
        return ans;
    }
};
