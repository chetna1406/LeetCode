class Solution{
    public:

    void fun(TreeNode* node, vector<int>&ans){
        if(node == NULL)
        return;
        ans.push_back(node->val);
        fun(node->left,ans);
        fun(node->right,ans);
    }
    vector<int> preorderTraversal(TreeNode* root){
        vector<int>ans;
        fun(root,ans);
        return ans;
    }
};