class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        if(nums.size() == 0)
            return nums;
        sort(nums.begin(),nums.end());
        int record = 1;

        int i = 0;
        while(record <= nums.size()){
            if(i >= nums.size()){
                ans.emplace_back(record);
                record++;
                continue;
            }
            if(nums[i] == record){
                i++;
                record++;
                continue;
            }
            else if(record > nums[i]){
                i++;
                continue;
            }
            else{
                ans.emplace_back(record);
                record++;
            }
        }

        // for(int i = 0; i < nums.size(); i++){
        //     if(nums[i] == record){
        //         record++;
        //         continue;
        //     }else if(record > nums[i])
        //         continue;
        //     else{
        //         while(record < nums[i]){
        //             ans.emplace_back(record);
        //             record++;
        //         }
        //         record++;
        //     }
        // }
        // int max = nums[nums.size() -1 ];
        // max++;
        // while(max <= nums.size()){
        //     ans.emplace_back(max);
        //     max++;
        // }
        return ans;
    }
};
