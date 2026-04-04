class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0,count2=0;
        int ele1=INT_MIN,ele2=INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(ele1==nums[i]){
                count1++;
            }
            else if(ele2==nums[i]){
                count2++;
            }
            else if(count1==0){
                count1=1;
                ele1=nums[i];
            }
            else if(count2==0){
                count2=1;
                ele2=nums[i];
            }
            else{
                count1--;
                count2--;
            }
        }
        count1 = count2 = 0;
        for(int num : nums){
            if(num == ele1){
                count1++;
            }
            if(num == ele2){
                count2++;
            }
        }
        vector<int>res;
        if(count1>nums.size()/3) {
            res.push_back(ele1);
        }if(count2>nums.size()/3) {
            res.push_back(ele2);
        }
        return res;
        
        
    }
    
};