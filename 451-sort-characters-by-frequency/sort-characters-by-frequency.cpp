class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for( char ch : s ){
            freq[ch]++;
        }
        priority_queue<pair<int,char>>maxHeap;
        for(auto &p : freq){
            maxHeap.push({p.second,p.first});
        }
        string st="";
        while(!maxHeap.empty()){
            auto p=maxHeap.top();
            maxHeap.pop();
            st.append(p.first, p.second); // char and number of times.
        }

        return st;
        
    }
};