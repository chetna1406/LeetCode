int search(int* nums, int numsSize, int target) {
    int l = 0, r = numsSize - 1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) return m;

        if (nums[l] <= nums[m]) { // Left half is sorted
            if (nums[l] <= target && target < nums[m])
                r = m - 1;
            else
                l = m + 1;
        } else { // Right half is sorted
            if (nums[m] < target && target <= nums[r])
                l = m + 1;
            else
                r = m - 1;
        }
    }
    return -1;
}
