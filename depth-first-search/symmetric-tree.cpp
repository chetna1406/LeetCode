class Solution {
public:
    bool fun(TreeNode* root1, TreeNode* root2) {
        if(root1 == NULL && root2 == NULL) 
        return true;

        if(root1 == NULL || root2 == NULL) 
        return false;

        if(root1->val != root2->val) 
        return false;

        bool a = fun(root1->left,root2->right);
        bool b = fun(root1->right,root2->left);

        if(a== true && b== true) 
        return true;

        return false;

    }
    bool isSymmetric(TreeNode* root) {
        return fun(root->left, root->right);
    }
};