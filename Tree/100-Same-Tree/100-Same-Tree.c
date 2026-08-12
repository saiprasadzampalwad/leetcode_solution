/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void sametree(struct TreeNode* p, struct TreeNode* q, int* a, int* b, int* i) {
    if (p == NULL && q == NULL) {
        return;
    }
    if (q == NULL) {
        b[*i] = -99999;
    } else {
        b[*i] = q->val;
    }
    if (p == NULL) {
        a[*i] = -99999;
    } else {
        a[*i] = p->val;
    }
    (*i)++;
    if(*i>100)
    {
         a=(int*)malloc((*i)*sizeof(int));
         b=(int*)malloc((*i)*sizeof(int));
    }
    if(p!=NULL&&q!=NULL)
    {
    sametree(p->left, q->left, a, b, i);
    sametree(p->right, q->right, a, b, i);
     }
      return;
}

bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    int *a=(int*)malloc(1000*sizeof(int));
     int *b=(int*)malloc(1000*sizeof(int));
    int i = 0;
    sametree(p, q, a, b, &i);
    for (int j = 0; j <= i; j++) {
        if (a[j] != b[j]) {
            free(a);
            free(b);
            return false;
        }
    }
    return true;
}
