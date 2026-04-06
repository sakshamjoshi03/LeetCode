class Solution {
public:
    int computreLPS(string s) {
        int n=s.length();
        vector<int>p(n,0);
        for(int i=1;i<n;i++){
            int j=p[i-1];
            if(s[j]==s[i]){
                p[i]=j+1;
                continue;
            }
            else{
                while(j>0 && s[i]!=s[j]){
                    j--;
                    j=p[j];
                }
                if(s[i]==s[j]){
                    p[i]=j+1;
                }
            }
        }
        return p[n-1];

    }
    string longestPrefix(string s){
        return s.substr(0,computreLPS(s));
    }
};