class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int notDeleted = arr[0];
        int deleted = 0;
        int maxSum = arr[0];

        for (int i = 1; i < arr.size(); i++) {
            int num = arr[i];
            int prevNotDeleted = notDeleted;
            int prevDeleted = deleted;
            notDeleted = max(prevNotDeleted + num, num);
            deleted = max(prevDeleted + num, prevNotDeleted);

            maxSum = max({maxSum, notDeleted, deleted});
        }
        return maxSum;
    }
};