int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}
int longestConsecutive(int* nums, int numsSize) {
    if(numsSize==0){return 0;}
    qsort(nums, numsSize, sizeof(int), cmp);
    int longest = 1, currentStreak = 1;
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]==nums[i-1])
        {
            continue;
        }
        else if(nums[i]==nums[i-1]+1)
        {
            currentStreak++;
        }
        else
        {
            if(currentStreak>longest)
            {
                longest=currentStreak;
            }
            currentStreak=1;
        }
    }
         if(currentStreak>longest)
            {
                longest=currentStreak;
            }
    
        return longest;
}
