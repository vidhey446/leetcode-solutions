#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int** threeSum(int* nums, int n, int* returnSize,
               int** returnColumnSizes) {
    
    int **ans = malloc(n * n * sizeof(int*));
    *returnColumnSizes = malloc(n * n * sizeof(int));
    *returnSize = 0;

    qsort(nums, n, sizeof(int), cmp);

    for(int i = 0; i < n - 2; i++) {
        if(i > 0 && nums[i] == nums[i-1])
            continue;

        int l = i + 1, r = n - 1;

        while(l < r) {
            int sum = nums[i] + nums[l] + nums[r];

            if(sum == 0) {
                ans[*returnSize] = malloc(3 * sizeof(int));

                ans[*returnSize][0] = nums[i];
                ans[*returnSize][1] = nums[l];
                ans[*returnSize][2] = nums[r];

                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                while(l < r && nums[l] == nums[l+1]) l++;
                while(l < r && nums[r] == nums[r-1]) r--;

                l++;
                r--;
            }
            else if(sum < 0)
                l++;
            else
                r--;
        }
    }

    return ans;
}