class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n=nums.size();
       vector<int>res(n);

       res[0]=1;
       for(int i=1;i<n;i++){
        res[i]=res[i-1]*nums[i-1];
       }// as the i-1th res didn't include i-1th nums

       int rightProd=1;

       for(int r=n-1;r>=0;r--){
        res[r]=res[r]*rightProd;
        rightProd*=nums[r];
       }
       return res;
    }
};