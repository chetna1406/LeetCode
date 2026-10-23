class Solution{
    public:

    void fun(TreeNode* node, vector<int>&ans){
        if(node == nullptr)
        return;

        fun(node->left,ans);
        ans.push_back(node->val);
        fun(node->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root){
        vector<int>ans;
        fun(root, ans);
        return ans;
    }
};