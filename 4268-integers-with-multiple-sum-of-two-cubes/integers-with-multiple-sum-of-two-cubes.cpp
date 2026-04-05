class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int x=cbrt(n);
        vector<int>ans;
        map<int,set<pair<int,int>>>mp;
        for(int a=0;a<=x;a++){
            for(int b=a;b<=x;b++){
                int a3=a*a*a;
                int b3=b*b*b;
                int mx=a3+b3;
                if(mx>n){
                    break;
                }
                mp[mx].insert({a,b});
            }
        }
        for(auto i : mp){
            if(i.second.size()>=2){
                ans.push_back(i.first);
            }
        }
        return ans;

    }
};