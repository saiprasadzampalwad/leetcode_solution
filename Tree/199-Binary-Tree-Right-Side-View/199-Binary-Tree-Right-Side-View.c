/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void rightHelper(struct TreeNode* root, int level, int* levels, int** rightView,
                 int* size) {
    if (root == NULL) {
        return;
    }
    if (levels[level] == 0) {
        (*rightView)[*size] = root->val;
        (*size)++;
        levels[level] = 1;
    }
    rightHelper(root->right, level + 1, levels, rightView, size);
    rightHelper(root->left, level + 1, levels, rightView, size);
}
int* rightSideView(struct TreeNode* root, int* returnSize) {
    if (root == NULL) {
        *returnSize = 0;
        return NULL;
    }
    int maxLevel = 100;
    int* levels = (int*)calloc(maxLevel, sizeof(int));
    int* rightView = (int*)malloc(maxLevel * sizeof(int));
    *returnSize = 0;
    rightHelper(root, 0, levels, &rightView, returnSize);
    return rightView;
}
