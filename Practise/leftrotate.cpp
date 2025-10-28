class Solution {
public:
    void rotate(vector<int>& nums, int k) {
    int n=size(nums);
     k=k%n;
     if(k==0)
     return;
     vector<int>temp(nums);
     for(int i=0;i<n;i++)
     {
        
      nums[(n+i-k)%n]=temp[i];
    }

    }
};
