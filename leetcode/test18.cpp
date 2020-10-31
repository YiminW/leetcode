class Solution {

private:
    vector<int> numsM;
    int tarM;
    vector<vector<int>> ansM;
    vector<int> ansOneM;
    int sizeM;

    void dfs(int index, int sum){
        if(ansOneM.size() <= 4){
            if(sum == tarM && ansOneM.size() == 4){
                ansM.emplace_back(ansOneM);
                return;
            }
            for(int i = index; i < sizeM; ++i){
                int sizeAnsOne = ansOneM.size();
                if(sizeM - i < int(4 - sizeAnsOne))
                    return;
                if(i < sizeM - 1 && sum + numsM[i] + numsM[i+1] * int(3 - sizeAnsOne) > tarM)
                    return;
                if(i < sizeM - 1 && sum + numsM[i] + numsM[sizeM - 1] * int(3- sizeAnsOne) < tarM)
                    continue;
                if(i > index && numsM[i] == numsM[i - 1])
                    continue;

                ansOneM.emplace_back(numsM[i]);
                dfs(i + 1, sum + numsM[i]);
                ansOneM.pop_back();
            }
        }
        return;
    }

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        numsM = nums;
        sizeM = nums.size();
        tarM = target;
        if(sizeM < 4)
            return ansM;
        dfs(0, 0);
        return ansM;
    }
};
