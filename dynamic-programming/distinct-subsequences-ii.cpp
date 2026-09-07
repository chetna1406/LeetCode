class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(26, 0);
        for (char c : s) {
            int i = c - 'a';
            long long sum = 1; 
            for (int x : dp)
                sum = (sum + x) % MOD;
            dp[i] = sum;
        }
        long long ans = 0;
        for (long long x : dp)
        ans = (ans + x) % MOD;
        return ans;
    }
};