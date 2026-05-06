class Solution {
public:
    int adjSum(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++){
            int take = nums[i-1];
            if(i>1) take+=dp[i-2];
            int not_take=0+dp[i-1];
            dp[i]=max(take,not_take);
        }
        return dp[n];
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n == 1) return nums[0];
        vector<int>arr1(n-1);
        vector<int>arr2(n-1);
        for(int i=0;i<n;i++){
            if(i!=0 )arr1.push_back(nums[i]);
            if(i!=n-1)arr2.push_back(nums[i]);
        }
        return max(adjSum(arr1),adjSum(arr2));
    }
};