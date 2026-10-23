class Solution{
    public:
    void fun(TreeNode* node, vector<int>&ans){
        if(node == NULL)
        return;

        fun(node->left,ans);
        fun(node->right,ans);
        ans.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root){
        vector<int>ans;
        fun(root,ans);
        return ans;
    }
};