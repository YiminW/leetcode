class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> ans;
        int lenA = A.size();
        int lenB = B.size();
        if(lenA == 0 || lenB == 0)
            return ans;
        long int a = 0;
        long int b = 0;
        while((a < A.size()) && (b < B.size())){
            if(A[a][0] > B[b][1]){
                b++;
                continue;
            }
            if(B[b][0] > A[a][1]){
                a++;
                continue;
            }

            if((B[b][0] <= A[a][1] && B[b][1] >= A[a][0]) || (A[a][0] <= B[b][1] && A[a][1] >= B[b][0])){
                vector<int> tmp;
                tmp.emplace_back(max(A[a][0], B[b][0]));
                tmp.emplace_back(min(A[a][1], B[b][1]));
                ans.emplace_back(tmp);

                if(A[a][1] < B[b][1]){
                    a++;
                    continue;
                }
                else if(A[a][1] > B[b][1]){
                    b++;
                    continue;
                }
                else{
                    a++;
                    b++;
                    continue;
                }
            }
        }
        return ans;
    }
};
