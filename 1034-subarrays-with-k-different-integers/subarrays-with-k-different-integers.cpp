class Solution {
public:
    int atMost(vector<int>& nums, int k) {
        unordered_map<int,int>freq;
        int left=0,count=0;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0){
                     freq.erase(nums[left]);
                }
                left++;
            }
            count+=i-left+1;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k){
        return atMost(nums,k)-atMost(nums,k-1);
    }
};