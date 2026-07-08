class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size(),csum=0;
        unordered_map<int,int>freq;
        freq[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
            csum+=nums[i];
            if(freq.find(csum-k)!=freq.end()){
                count+=freq[csum-k];
            }
            freq[csum]++;
        }
        return count;

    }
};