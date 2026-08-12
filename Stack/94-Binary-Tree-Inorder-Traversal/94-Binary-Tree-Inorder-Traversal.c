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
 void inorderHelper(struct TreeNode* root, int* result, int* returnSize) 
 {
     if (root == NULL) {
         return; 
         } 
         inorderHelper(root->left, result, returnSize);
          result[(*returnSize)++] = root->val; 
          inorderHelper(root->right, result, returnSize);
 }
 
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
  * returnSize=0;
  int* result = (int*)malloc(100 * sizeof(int));
  inorderHelper(root, result, returnSize);
  result = (int*)realloc(result, (*returnSize) * sizeof(int));
  return result;
}