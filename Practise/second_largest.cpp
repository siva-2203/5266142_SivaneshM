    int getSecondLargest(vector<int> &arr) {
        // code here
        int n=arr.size();
        int max=INT_MIN;
        for(int i=0;i<n;i++)
        {
            if(arr[i]>max)
            {
                max=arr[i];
            }
        }
        int sec_max=INT_MIN;
        for(int j=0;j<n;j++)
        {
            if(arr[j]>sec_max && arr[j]!=max)
            {
                sec_max=arr[j];
            }
        }
        if(sec_max==INT_MIN)
        {
            return -1;
        }
        return sec_max;
    }
