/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int height(struct TreeNode* root)
{
    // Empty tree
    if (root == NULL)
        return 0;

    // Get heights of left and right subtrees
    int leftHeight = height(root->left);

    // Left subtree is already unbalanced
    if (leftHeight == -1)
        return -1;

    int rightHeight = height(root->right);

    // Right subtree is already unbalanced
    if (rightHeight == -1)
        return -1;

    // Check balance factor
    if (abs(leftHeight - rightHeight) > 1)
        return -1;

    // Return height of current subtree
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

bool isBalanced(struct TreeNode* root)
{
    return height(root) != -1;
}