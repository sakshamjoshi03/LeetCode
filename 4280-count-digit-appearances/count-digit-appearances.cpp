class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count=0;
        for(int i=0;i<nums.size();i++){
            int copy=nums[i];
            if (copy==0 && digit==0) {
                count++;
            }
            while(copy>0){
                int num=copy%10;
                if(num==digit){
                    count++;
                }
                copy=copy/10;
            }
        }
        return count;
    }
};