class Solution {
public:
    bool prime(int n){
        if(n<=1) return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        map<int,int>freq;
        for(auto c : nums ){
            freq[c]++;
        }
        for(auto &it :freq){
            if(prime(it.second)){
                return true;
            }
        }
        return false;
    }
};