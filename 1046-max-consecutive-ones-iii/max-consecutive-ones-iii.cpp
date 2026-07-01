class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zcnt=0;
        int maxi=0;
        int left=0;
        for(int r=0;r<nums.size();r++){
            if(nums[r]==0) zcnt++;
            if(zcnt>k){
                if(nums[left]==0) zcnt--;
                left++;
            }
            maxi=max(maxi,r-left+1);
        }
        return maxi;

    }
};