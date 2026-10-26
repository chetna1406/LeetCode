class Solution {
public:
    TreeNode* ans = NULL;

    void fun(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return;

        if(root->val < p->val && root->val < q->val)
            fun(root->right, p, q);
        else if(root->val > p->val && root->val > q->val)
            fun(root->left, p, q);
        else {
            ans = root;
            return;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fun(root, p, q);
        return ans;
    }
};