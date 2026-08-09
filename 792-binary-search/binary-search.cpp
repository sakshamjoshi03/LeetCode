class Solution {
public:
    int Bsearch(vector<int>& nums, int target,int left, int right){
        if(left>right){
            return -1;
        }
            int mid=left+(right-left)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<target){
                return Bsearch(nums,target,mid+1,right);
            }
            else {
                return Bsearch(nums,target,left,mid-1);
            }
    }
    int search(vector<int>& nums, int target) {
        return Bsearch(nums,target,0,nums.size()-1);
    }
};