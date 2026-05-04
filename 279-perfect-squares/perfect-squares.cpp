class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,0);
        if(n<=0) return dp[0]; 
        for(int i=1;i<=n;i++){
            int j=1;
            dp[i]=INT_MAX;
            while(j*j<=i){
                dp[i]=min(dp[i],dp[i-j*j]+1);
                j++;
            }
        }
        return dp[n];
    }

};