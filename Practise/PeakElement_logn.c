int findPeakElement(int* nums, int numsSize) {
    if(numsSize==1)
    {
        return 0;
    }
    if(numsSize==2)
    {
        if(nums[0]>nums[1])
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    int low=0;
    int high=numsSize-1;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(mid==0)
        {
            if(nums[mid]<nums[mid+1])
            {
                return mid+1;
            }
            else
            {
                return mid;
            }
        }
        if(mid==numsSize-1)
        {
            if(nums[mid]>nums[mid-1])
            {
                return mid;
            }
            else
            {
                return mid-1;
            }
        }
        if(mid>=1 && mid<numsSize-1)
        {
        if(nums[mid]>nums[mid-1] && nums[mid]>nums[mid+1])
        {
            return mid;
        }
        else if(nums[mid]<nums[mid+1])
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
        }
        else
        {
            break;
        }
    }
    return -1;
}
