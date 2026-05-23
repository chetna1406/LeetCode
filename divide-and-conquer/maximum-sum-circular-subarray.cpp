class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;

        int curMax = 0, maxSum = nums[0];
        int curMin = 0, minSum = nums[0];

        for (int x : nums) {
            // Kadane for max subarray
            curMax = max(x, curMax + x);
            maxSum = max(maxSum, curMax);

            // Kadane for min subarray
            curMin = min(x, curMin + x);
            minSum = min(minSum, curMin);

            totalSum += x;
        }

        // If all numbers are negative
        if (maxSum < 0) return maxSum;

        return max(maxSum, totalSum - minSum);
    }
};
