class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int current_sum=0;
        int maxi=nums[0];
        for(int i=0;i<n;i++){
            current_sum+=nums[i];
            maxi=max(maxi,current_sum);
            if(current_sum<0){
                current_sum=0;
            }
        }
        return maxi;
    }
};