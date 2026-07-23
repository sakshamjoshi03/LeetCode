class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>st1;
        stack<char>st2;
        for(int i=0;i<s.length();i++){
           if(s[i] =='#'){
                if(!st1.empty()) st1.pop();
            }
            else st1.push(s[i]);
        }
        for(int i=0;i<t.length();i++){
           if(t[i] =='#'){
                if(!st2.empty()) st2.pop();
            }
            else st2.push(t[i]);
        }
        string s1="";
        string t1="";
        while(!st1.empty()){
            s1.push_back(st1.top());
            st1.pop();
        }
        while(!st2.empty()){
            t1.push_back(st2.top());
            st2.pop();
        }
        return t1==s1;
    }
};