/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> onePro;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {

        dfs(root, sum);
        return ans;
    }

    void dfs(TreeNode* node, int sum){
        if(node == nullptr)
            return;
        
        onePro.emplace_back(node->val);
        sum -= node->val;

        if(node -> left == nullptr && node -> right == nullptr && sum == 0){
         //   if(sum == 0){ //solution 2
                ans.emplace_back(onePro);
         //   }
            // else{
            //     onePro.pop_back();
            //     return;
            // }
        }

        dfs(node->left, sum);
        dfs(node->right, sum);
        onePro.pop_back();
    }
};
