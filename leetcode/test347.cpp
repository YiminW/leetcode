class Solution {
public:
    struct pairFre{
        int element;
        int num;
        pairFre(int a = 0, int b = 0){
            element = a;
            num = b;
        }
    };
    struct cmp{
         bool operator () (pairFre a, pairFre b)
        {
            return a.num > b.num ;
        }
    };

    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int, int> frequence;
        for(int n: nums){
            frequence[n]++;
        }
        priority_queue<pairFre, vector<pairFre>, cmp> q;

        for(auto onePair : frequence)
        {
            q.push(pairFre(onePair.first, onePair.second));
            if(q.size() > k)
                q.pop();
        }

        while(k > 0){
            ans.emplace_back(q.top().element);
            q.pop();
            k--;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
