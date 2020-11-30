class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int left = findLeft(nums, target);
        int right = findRight(nums, target, left);
        ans.emplace_back(left);
        ans.emplace_back(right);
        return ans;
    }

    int findLeft(const vector<int>& nums, const int& target){
        if(nums.size() == 0)
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                if(mid > 0 && nums[mid - 1] < target){
                    return mid;
                }
                else if(mid == 0){
                    return mid;
                }
                else{
                    right = mid - 1;
                }
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }

    int findRight(const vector<int>& nums, const int& target, int left){
        if(left == -1)
            return -1;
        if(nums.size() == 0)
            return -1;
        //int left = 0;
        int right = nums.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[mid] == target){
                if(mid + 1 < nums.size() && nums[mid + 1] > target){
                    return mid;
                }
                else if(mid + 1 == nums.size()){
                    return mid;
                }
                else{
                    left = mid + 1;
                }
            }
            else if(nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
};
