//
//  test53.cpp
//  leetcode
//
//  Created by 王益民 on 2020/10/22.
//

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //int len = nums.size();
        //if(len == 0)
            //return 0;
        //if(len == 1)
        //    return nums[0];
        //int right = 1;
        int sum = 0;
        int result = INT_MIN;
        for(int right = 0;right < nums.size(); right++)
        {
            sum = max(nums[right], sum + nums[right]);
            result = max(sum, result);
        }
        return result;
        //return sum;
    }
};
