class Solution {
public:
    vector<vector<int>> ans;

    void fun(vector<int>& a, int n, int idx, vector<int>& temp) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }

        // Don't take
        fun(a, n, idx + 1, temp);

        // Take
        temp.push_back(a[idx]);
        fun(a, n, idx + 1, temp);

        // Backtrack
        temp.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& a) {
        vector<int> temp;
        fun(a, a.size(), 0, temp);
        return ans;
    }
};