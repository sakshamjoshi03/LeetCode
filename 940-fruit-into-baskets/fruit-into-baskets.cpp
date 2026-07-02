class Solution {
public:
    int totalFruit(vector<int>& nums) {
        unordered_map<int,int>freq;
        int n=nums.size();
        int left=0;
        int maxi=0;
        int window=0;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
            while(freq.size()>2){
                freq[nums[left]]--;
                if (freq[nums[left]] == 0){
                    freq.erase(nums[left]);
                }
                left++;
            }
            maxi=max(maxi,i-left+1);
        }
        return maxi;
    }
};