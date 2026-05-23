int binary(int* nums, int n, int target, int findFirst) {
    int l = 0, r = n - 1, res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (nums[m] == target) {
            res = m;
            if (findFirst) r = m - 1;
            else l = m + 1;
        } else if (nums[m] < target)
            l = m + 1;
        else
            r = m - 1;
    }
    return res;
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* res = malloc(2 * sizeof(int));
    *returnSize = 2;
    res[0] = binary(nums, numsSize, target, 1);
    res[1] = binary(nums, numsSize, target, 0);
    return res;
}
