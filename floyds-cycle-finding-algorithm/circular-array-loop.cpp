class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            int slow = i, fast = i;
            bool forward = nums[i] > 0;
            while (true) {
                slow = next(nums, slow, forward);
                fast = next(nums, fast, forward);
                if (fast != -1)
                    fast = next(nums, fast, forward);
                if (slow == -1 || fast == -1) break;
                if (slow == fast) return true;
            }
            int val = i;
            while (nums[val] != 0 && (nums[val] > 0) == forward) {
                int nxt = ((val + nums[val]) % n + n) % n;
                nums[val] = 0;
                val = nxt;
            }
        }
        return false;
    }
    int next(vector<int>& nums, int idx, bool forward) {
        bool dir = nums[idx] > 0;
        if (dir != forward) return -1;
        int n = nums.size();
        int nextIdx = ((idx + nums[idx]) % n + n) % n;
        if (nextIdx == idx) return -1; 
        return nextIdx;
    }
};
