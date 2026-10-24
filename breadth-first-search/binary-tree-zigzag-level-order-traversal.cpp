class Solution{
    public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>>res;

        if(root==NULL) return res;

        queue<TreeNode* >q;
        q.push(root);

        while(!q.empty()){
            int lvlsize = q.size();
            vector<int>temp;
            while(lvlsize--){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                
                if(t->left != NULL)
                q.push(t->left);

                if(t->right != NULL)
                q.push(t->right);
            }
            res.push_back(temp); 
        }
        for(int i = 0; i < res.size(); i++){
            if(i % 2 == 1){
                reverse(res[i].begin(),res[i].end());
            }
        }
        return res;
    }
};