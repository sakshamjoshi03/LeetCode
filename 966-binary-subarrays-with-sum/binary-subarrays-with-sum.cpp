class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) { int n=nums.size(),csum=0;
        unordered_map<int,int>freq;
        freq[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
            csum+=nums[i];
            if(freq.find(csum-goal)!=freq.end()){
                count+=freq[csum-goal];
            }
            freq[csum]++;
        }
        return count;
    }
};