class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k){
     int n=nums.size();
     unordered_map<int, int> freq;
     long long windowsum=0,maxsum=0;
     for(int i=0;i<k;i++){
         windowsum+=nums[i];
         freq[nums[i]]++;
     }
     if(freq.size()==k){
         maxsum=windowsum;
     }
     for(int j=k;j<n;j++){
         windowsum+=nums[j];
         freq[nums[j]]++;
         windowsum-=nums[j-k];
         freq[nums[j-k]]--;
            if (freq[nums[j - k]] == 0){
                freq.erase(nums[j - k]);
            }
            if (freq.size() == k){
                maxsum = max(maxsum, windowsum);
            }
     }
     return maxsum;
    }
};