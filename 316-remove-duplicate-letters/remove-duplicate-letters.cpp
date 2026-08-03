class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>lastoccur(26);
        vector<bool>vis(26,false);
        for(int i=0;i<s.size();i++){
            lastoccur[s[i]-'a']=i;
        }
        string stack;
        for(int i=0;i<s.size();i++){
            char ch=s[i];

            if(vis[ch-'a']){
                continue;
            }
            while(!stack.empty()&&stack.back()>ch&&lastoccur[stack.back()-'a']>i){
                vis[stack.back()-'a']=false;
                stack.pop_back();
            }
            stack.push_back(ch);
            vis[ch-'a']=true;
        }
        return stack;
    }
};