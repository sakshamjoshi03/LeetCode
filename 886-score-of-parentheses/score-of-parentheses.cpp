class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        for (int i=0;i<s.length();i++) {
            if (s[i]=='(') {
                st.push(-1); // -1 represents '('
            }
            else {
                if(st.top()==-1) {      // Found "()"
                    st.pop();
                    st.push(1);
                }
                else {
                    int sum=0;
                    while(st.top()!=-1) {
                        sum+=st.top();
                        st.pop();
                    }
                    st.pop();              // Remove '('
                    st.push(2 *sum);
                }
            }
        }
        int ans=0;
        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};