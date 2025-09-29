class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int mid;
        int l=0;
        int h=arr.size()-1;
        while(l<=h)
        {
            mid=l+((h-l)/2);
            if(arr[mid]<target)
            {
               l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return l;
    }
};

