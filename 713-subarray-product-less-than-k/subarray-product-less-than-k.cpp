class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      int n=nums.size();
      int left=0;
      int count=0;
      int window=1;
      for(int right=0;right<n;right++){
        window=window*nums[right];
        while(window>=k){
            window=window/nums[left];
            left++;
        }
        count+=right-left+1;
      }
      return count;  
    }
};