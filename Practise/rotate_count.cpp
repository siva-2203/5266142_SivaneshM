class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int low=0;
        int n=arr.size();
        int high=arr.size()-1;
        while(low<=high)
        {
            if(arr[low]<=arr[high])
            {
                return low;
            }
            int mid=low+(high-low)/2;
            int next=(mid+1)%n;
            int prev=(mid+n-1)%n;
            if(arr[mid]<=arr[next] && arr[mid]<=arr[prev])
            {
                return mid;
            }
            if(arr[mid]>=arr[low])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return 0;
        
    }
};

