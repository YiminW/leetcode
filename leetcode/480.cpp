class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> ans;
        multiset<int> windows(nums.begin(), nums.begin() + k);
        auto midIter = next(windows.begin(), k/2);  //k为偶数时偏后
       
        if(k%2 == 0)
            ans.emplace_back( ( (double)*midIter + (double)*prev(midIter) )  * 0.5);
        else
            ans.emplace_back(*midIter);

        for(int i = k; i < nums.size(); i++){
            windows.insert(nums[i]);

            // if(nums[i] < *midIter && nums[i - k] > *midIter)
            //     midIter--;
            // else if(nums[i] >= *midIter && nums[i - k] <= *midIter)
            //     midIter++;

            if(nums[i] < *midIter)
                midIter--;
            if(nums[i - k] <= *midIter)
                midIter++;

            windows.erase(windows.lower_bound(nums[i - k]));

            if(k%2 == 0)
                ans.emplace_back( ( (double)*midIter + (double)*prev(midIter) )  * 0.5);
            else
                ans.emplace_back(*midIter);
            
        }

        return ans;
    }

 

};
