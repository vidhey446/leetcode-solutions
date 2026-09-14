/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool check(struct TreeNode* l,struct TreeNode* r){
    if(l == NULL && r == NULL){
        return true;
    }

    if(l == NULL || r == NULL){
        return false;
    }
    if (l->val != r->val){
        return false;
    }
    if ((l->left == NULL && r->right != NULL) || (l->left != NULL && r->right == NULL) ){
        return false;
    }

    if ((l->right == NULL && r->left != NULL) || (l->right != NULL && r->left == NULL) ){
        return false;
    }

    return check(l->right,r->left) && check(l->left,r->right);

}


bool isSymmetric(struct TreeNode* root) {
    if(root == NULL){
        return true;
    }

    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;


    return check(left,right);
}