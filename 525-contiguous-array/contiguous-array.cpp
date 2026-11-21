class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>freq;
        int sum = 0;
        int maxi = 0;

        freq[0] = -1;

        for(int i = 0; i < nums.size() ; i++){
            sum += (nums[i]==1?1:-1);
             if(freq.count(sum)) {
                maxi = max(maxi, i - freq[sum]);
            }
            else {
                freq[sum] = i;
            }
            
        }

        return maxi;
    }
};