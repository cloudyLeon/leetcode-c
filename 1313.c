/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define MAXSIZE 5000
int* decompressRLElist(int* nums, int numsSize, int* returnSize);
int main() {
    int ary[4] = {1,2,3,4};
    int *res;
    int *returnsize;
    res = decompressRLElist(ary, 4,returnsize);
    for(int i=0; i < *returnsize; i++){
        printf("%d ",res[i]);
    }
    printf("\n");
}
int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int i = 0;
    int j = 0;
    int k = 0;
    int ret[MAXSIZE] = {0};
    int temp = 0;
    int *end = NULL;

    for(i = 0, j = 0; i < numsSize/2; i++) {
        //temp = nums[2 * i + 1];
        //memset(&ret[j], temp, nums[2 * i] * sizeof(int));
        k = nums[2 * i];
        while (k != 0) {
            ret[j] = nums[2 * i + 1];
            j++;
            k--;
        }
    }
    //printf("j = %d\n",j);
    *returnSize = j;
    end = (int *)malloc(j * sizeof(int));
    memset(end, 0x00, j * sizeof(int));
    memcpy(end, ret, j * sizeof(int));
    return end;
}