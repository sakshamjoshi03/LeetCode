class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        long long prefix=0,suffix=0;
        int n=nums.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        for(int i=0;i<n;i++){
            suffix=total-prefix-nums[i];//nums[i] is pivot so shouldn't consider it.
            if(suffix==prefix){
                return i;
            }
            prefix+=nums[i];
        }
        return -1;
    }
};