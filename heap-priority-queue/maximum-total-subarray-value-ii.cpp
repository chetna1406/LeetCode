class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();

        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;

        vector<vector<int>> mn(LOG, vector<int>(n));
        vector<vector<int>> mx(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            mn[0][i] = mx[0][i] = nums[i];
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                mn[j][i] = min(mn[j - 1][i],
                               mn[j - 1][i + (1 << (j - 1))]);
                mx[j][i] = max(mx[j - 1][i],
                               mx[j - 1][i + (1 << (j - 1))]);
            }
        }

        vector<int> lg(n + 1);
        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

        auto val = [&](int l, int r) {
            int len = r - l + 1;
            int p = lg[len];

            long long mnv = min(mn[p][l], mn[p][r - (1 << p) + 1]);
            long long mxv = max(mx[p][l], mx[p][r - (1 << p) + 1]);

            return mxv - mnv;
        };

        struct Node {
            long long v;
            int l, r;

            bool operator<(const Node& other) const {
                return v < other.v;
            }
        };

        priority_queue<Node> pq;

        for (int l = 0; l < n; l++) {
            pq.push({val(l, n - 1), l, n - 1});
        }

        long long ans = 0;

        while (k--) {
            auto cur = pq.top();
            pq.pop();

            ans += cur.v;

            if (cur.r > cur.l) {
                pq.push({val(cur.l, cur.r - 1),
                         cur.l,
                         cur.r - 1});
            }
        }

        return ans;
    }
};