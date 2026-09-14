/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root == NULL){
        return false;
    }

    if(root->val == targetSum && root->left == NULL && root->right == NULL){
        return true;
    }

    bool left = hasPathSum(root->left,targetSum - root->val);
    bool right = hasPathSum(root->right,targetSum - root->val);

    return (left || right);
}