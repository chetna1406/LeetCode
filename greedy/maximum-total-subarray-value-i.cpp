class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        
        int mn = INT_MAX;
        int mx = INT_MIN;

        for(int x : nums)
        {
            mn = min(x, mn);
            mx = max(x, mx);
        }

        return 1LL * (mx - mn) * k;
    }
};