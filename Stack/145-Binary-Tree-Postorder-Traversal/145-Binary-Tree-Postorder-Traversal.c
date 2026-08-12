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
 void postorderHelper(struct TreeNode* root, int* result, int* returnSize) 
 {
     if (root == NULL) {
         return; 
         } 
         postorderHelper(root->left, result, returnSize);
          postorderHelper(root->right, result, returnSize);
          result[(*returnSize)++] = root->val; 
 }
 
int* postorderTraversal(struct TreeNode* root, int* returnSize) {
  * returnSize=0;
  int* result = (int*)malloc(100 * sizeof(int));
  postorderHelper(root, result, returnSize);
  result = (int*)realloc(result, (*returnSize) * sizeof(int));
  return result;
}

    
