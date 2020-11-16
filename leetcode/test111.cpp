/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root) {
        //深度优先
        /**
        if(root == nullptr)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        
        int res = INT_MAX;

        if(root->left != nullptr)
            res = min(res, minDepth(root->left));
        if(root->right != nullptr)
            res = min(res, minDepth(root->right));
        
        return res + 1;
        **/

        //广度优先
        if(root == nullptr)
            return 0;
        int ans = 1;
        queue <TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int currentLen = q.size();
            for(int i = 0; i < currentLen; i++){    
                TreeNode* node = q.front();
                q.pop();
                if(node->left == nullptr && node->right == nullptr)
                    return ans;
                else{
                    if(node->left != nullptr)
                        q.push(node->left);
                    if(node->right != nullptr)
                        q.push(node->right);
                }
            }
            ans++;
        }
        return ans;

    }
};
