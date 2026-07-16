class Solution {
public:
    vector<int> asteroidCollision(vector<int>& aster) {
        int n=aster.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            bool destroyed=false;
            while(!st.empty() && st.top()>0 && aster[i]<0){
                if(st.top()<-aster[i]){
                    st.pop();
                }
                else if(st.top()==-aster[i]){
                    destroyed=true;
                    st.pop();
                    break;
                }
                else{
                    destroyed=true;
                    break;
                }

            }
            if(!destroyed){
                st.push(aster[i]);
            }
        }
        vector<int> res(st.size());
        for(int i=st.size()-1;i>=0;i--) {
            res[i]=st.top();
            st.pop();
        }

        return res;
    }
};