class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int res = nums[0] + nums[1] + nums[2];
        for(int i = 0; i < len - 2; i++){
            int left = i + 1;
            int right = len - 1;
            //bool sT(false), lT(false);
            //while((left < right) && (!sT || !lT)){
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                int sumL = sum - nums[left] + nums[left+1];
                int sumS = sum - nums[right] + nums[right - 1];
                if(sum == target)
                    return sum;
                else if(sum < target){
                    res = (abs(target - sum) <= abs(res - target))?sum:res;
                    left++;
                    //sT = true;
                }
                else{
                    //lT = true;
                    res = (abs(target - sum) <= abs(res - target))?sum:res;
                    right--;
                }
            }
        }
        return res;
    }
};
