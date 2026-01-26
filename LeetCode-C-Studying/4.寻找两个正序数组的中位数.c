int qsort_int (const void *nums1, const void *nums2) {
    return *(int*)nums1 - *(int*)nums2;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int* numstotal = (int*)calloc(nums1Size + nums2Size, sizeof(int));
    for (int i = 0; i < nums1Size; numstotal[i] = nums1[i], i++);
    for (int j = 0; j < nums2Size; numstotal[nums1Size + j] = nums2[j], j++);
    qsort(numstotal, nums1Size+nums2Size, sizeof(int), qsort_int);
    return (nums1Size+nums2Size)%2 ? numstotal[(nums1Size+nums2Size)/2] : (double)(numstotal[(nums1Size+nums2Size)/2 - 1] + numstotal[(nums1Size+nums2Size)/2]) / 2;
}