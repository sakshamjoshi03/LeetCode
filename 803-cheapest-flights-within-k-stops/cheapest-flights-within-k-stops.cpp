class Solution {
public:
   int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    vector<vector<pair<int,int>>>adj(n);
    for(auto &f : flights){
        adj[f[0]].push_back({f[1],f[2]});
    }
    vector<int>dist(n,INT_MAX);
    dist[src]=0;
    priority_queue<pair<int,pair<int,int>>,
    vector<pair<int,pair<int,int>>>,
    greater<pair<int,pair<int,int>>>> pq;
    pq.push({0,{src,0}});//stops , node , cost
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
         int stop = it.first;
         int node = it.second.first;
         int cost = it.second.second;
         if(stop>k) continue;
          for(auto &ad : adj[node]){
            int vtx=ad.first;
            int adjstop=ad.second;
            int tc=cost+adjstop;
            if(dist[vtx]>tc && stop <= k){
                dist[vtx]=tc;
                pq.push({stop+1,{vtx,tc}});
            }
          }
    }
    if ( dist[dst]==INT_MAX) return -1;
    return dist[dst];
   }
};