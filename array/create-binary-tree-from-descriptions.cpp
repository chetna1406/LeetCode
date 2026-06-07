class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {

        unordered_map<int, TreeNode*> mp;
        unordered_set<int> child;

        for(auto& d : descriptions) {

            int parent = d[0];
            int ch = d[1];
            int isLeft = d[2];

            if(mp.find(parent) == mp.end())
                mp[parent] = new TreeNode(parent);

            if(mp.find(ch) == mp.end())
                mp[ch] = new TreeNode(ch);

            if(isLeft)
                mp[parent]->left = mp[ch];
            else
                mp[parent]->right = mp[ch];

            child.insert(ch);
        }

        for(auto& d : descriptions) {
            int parent = d[0];

            if(child.find(parent) == child.end())
                return mp[parent];
        }

        return nullptr;
    }
};