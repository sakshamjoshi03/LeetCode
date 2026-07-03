class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
 deque<int>dq;
        vector<int>res;
        for(int i=0;i<k;i++){
            while(!dq.empty() && arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
        dq.push_back(i);//pushing index
        }
        for(int i=k;i<arr.size();i++){
            res.push_back(arr[dq.front()]);
            while(!dq.empty() && dq.front()<=i-k){
                dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()]<=arr[i]){
                dq.pop_back();
            }
            dq.push_back(i);//pushing index
        }
        res.push_back(arr[dq.front()]);
        return res;
    }
};