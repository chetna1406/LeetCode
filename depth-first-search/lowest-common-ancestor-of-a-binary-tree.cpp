class Solution {
public:
    TreeNode* ans = NULL;
    int fun(TreeNode* node, TreeNode* p, TreeNode* q){
        if(node == NULL)
        return 0;

        int left = fun(node->left,p,q);
        int right = fun(node->right,p,q);

        int self =0;
        if(p == node || q ==node)
        self=1;

        int total = left+right+self;

        if(total == 2 && ans == NULL)
        ans = node;

        return total;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        fun(root,p,q);
        return ans;
    }
};