/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int count_left = 1,count_right = 1;

    if(root == NULL){
        return 0;
    }

    if(root->left == NULL && root-> right == NULL){
        return count_left;
    }

    if (root->left == NULL){
        count_right += maxDepth(root->right);
    }else if (root->right == NULL) {
        count_left += maxDepth(root->left);
    }else{
        count_left += maxDepth(root->left);
        count_right += maxDepth(root->right);
    }
    
    

    if(count_right > count_left){
        return count_right;
    }

    return count_left;
}