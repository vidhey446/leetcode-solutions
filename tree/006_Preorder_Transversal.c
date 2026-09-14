/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/* Helper function */
void preorder(struct TreeNode* root, int* result, int* returnSize) {

    if (root == NULL) {
        return;
    }

    // ROOT
    result[*returnSize] = root->val;
    (*returnSize)++;

    // LEFT
    preorder(root->left, result, returnSize);

    // RIGHT
    preorder(root->right, result, returnSize);
}

int countNodes(struct TreeNode* root) {

    if (root == NULL) {
        return 0;
    }

    return 1 + countNodes(root->left) + countNodes(root->right);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {

    *returnSize = 0;

    int n = countNodes(root);

    if (n == 0) {
        return NULL;
    }

    int* result = malloc(n * sizeof(int));

    preorder(root, result, returnSize);

    return result;
}
