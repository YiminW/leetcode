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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == nullptr)
            return ans;

        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int currentSize = q.size();
            vector<int> d;
            for(int i = 0; i < currentSize; i++){
                auto node = q.front();
                q.pop();
                d.emplace_back(node->val);
                if(node -> left != nullptr)
                    q.push(node -> left);
                if(node -> right != nullptr)
                    q.push(node -> right);
            }
            ans.emplace_back(d);
        }
        return ans;
    }
};
