class Solution {
public:
    string makeGood(string s) {
        stack<int>st;
        string stk="";
        for(int i=0;i<s.length();i++){
            if(!st.empty() && abs(st.top() - s[i]) == 32){
                 st.pop();
            }
            else {st.push(s[i]);}
        }
        while(!st.empty()){
            stk.push_back(st.top());
            st.pop();
        }
        reverse (stk.begin(),stk.end()); 
        return stk;
    }
};