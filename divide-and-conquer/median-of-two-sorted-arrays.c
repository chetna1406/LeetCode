//chetna
#include <stdio.h>
#include <stdlib.h>

double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    int* merged = (int*)malloc((m + n) * sizeof(int));
    int i = 0, j = 0, k = 0;

    // Merge the two arrays
    while (i < m && j < n) {
        if (nums1[i] < nums2[j])
            merged[k++] = nums1[i++];
        else
            merged[k++] = nums2[j++];
    }
    while (i < m) merged[k++] = nums1[i++];
    while (j < n) merged[k++] = nums2[j++];

    // Find median
    int total = m + n;
    double median;
    if (total % 2 == 0)
        median = (merged[total/2 - 1] + merged[total/2]) / 2.0;
    else
        median = merged[total/2];

    free(merged);
    return median;
}