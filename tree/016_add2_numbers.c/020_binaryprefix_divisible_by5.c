/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* prefixesDivBy5(int* nums, int numsSize, int* returnSize) {
    bool* ans = malloc(numsSize * sizeof(bool));

    int rem = 0;

    for (int i = 0; i < numsSize; i++) {
        rem = (rem * 2 + nums[i]) % 5;
        ans[i] = (rem == 0);
    }

    *returnSize = numsSize;
    return ans;
}