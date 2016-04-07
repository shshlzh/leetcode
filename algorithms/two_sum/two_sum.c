#include <stdio.h>
#include <malloc.h>
#include <string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
	if (nums == NULL || numsSize < 2)  return NULL;

	int* rtn_array = (int*)malloc(sizeof(int) * 2);
	memset(rtn_array, 0, sizeof(int) * 2);

	int i, j, value;

	for (i = 0; i < numsSize; i++) {
		value = target - nums[i];
		for (j = i+1; j < numsSize; j++) {
			if (value != nums[j]) {
				continue;
			}else{
				rtn_array[0] = i;
				rtn_array[1] = j;
				return rtn_array;
			}
		}
	}
	free(rtn_array);
	return NULL;
}


int main(int argc, char* argv[]) {
	int nums[] = {3, 2, 0};
	int* rtn_array = twoSum(nums, 3, 2);
	printf("%d %d\n", rtn_array[0], rtn_array[1]);
	if(rtn_array) {
		free(rtn_array);
	}
	return 0;
}
