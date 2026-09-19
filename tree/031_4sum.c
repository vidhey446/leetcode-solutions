#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int** fourSum(int* nums, int n, int target,
              int* returnSize, int** returnColumnSizes) {

    int capacity = 1000;
    int **ans = malloc(capacity * sizeof(int*));
    *returnColumnSizes = malloc(capacity * sizeof(int));
    *returnSize = 0;

    qsort(nums, n, sizeof(int), cmp);

    for (int i = 0; i < n - 3; i++) {

        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; j++) {

            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            int l = j + 1;
            int r = n - 1;

            while (l < r) {

                long long sum = (long long)nums[i]
                              + nums[j] + nums[l] + nums[r];

                if (sum == target) {

                    ans[*returnSize] = malloc(4 * sizeof(int));

                    ans[*returnSize][0] = nums[i];
                    ans[*returnSize][1] = nums[j];
                    ans[*returnSize][2] = nums[l];
                    ans[*returnSize][3] = nums[r];

                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize)++;

                    while (l < r && nums[l] == nums[l + 1])
                        l++;

                    while (l < r && nums[r] == nums[r - 1])
                        r--;

                    l++;
                    r--;
                }
                else if (sum < target) {
                    l++;
                }
                else {
                    r--;
                }
            }
        }
    }

    return ans;
}