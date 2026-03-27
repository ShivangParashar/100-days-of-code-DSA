/*Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    #define SIZE 10000

    static int hashTable[10000][3]; 

    for (int i = 0; i < SIZE; i++)
        hashTable[i][2] = 0;

    
    int hash(int key) {
        if (key < 0) key = -key;
        return key % SIZE;
    }

    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 2;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        int idx = hash(complement);
        int start = idx;

        while (hashTable[idx][2]) {
            if (hashTable[idx][0] == complement) {
                result[0] = hashTable[idx][1];
                result[1] = i;
                return result;
            }
            idx = (idx + 1) % SIZE;
            if (idx == start) break;
        }

       
        idx = hash(nums[i]);
        while (hashTable[idx][2]) {
            idx = (idx + 1) % SIZE;
        }
        hashTable[idx][0] = nums[i];
        hashTable[idx][1] = i;
        hashTable[idx][2] = 1;
    }

    return NULL;
}
