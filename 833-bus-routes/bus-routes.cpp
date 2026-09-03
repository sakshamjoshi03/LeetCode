class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        unordered_map<int,vector<int>>mp;//{stop,<buses>}
        int n=routes.size();
        for(int i=0;i<n;i++){
            for(auto j:routes[i]){
                mp[j].push_back(i);
            }
        }
        queue<pair<int,int>>q; //{stop,minbuses}
        q.push({source,0});
        unordered_set<int>vis={source};

        while(!q.empty()){
            int s=q.front().first;
            int buses=q.front().second;

            if(s==target) return buses;

            q.pop();
            for(auto i:mp[s]){
                for(auto j:routes[i]){
                    if(vis.find(j)==vis.end()){
                        vis.insert(j);
                        q.push({j,buses+1});
                    }
                }
                routes[i].clear();
            }
        }
         return -1;
    }
};
