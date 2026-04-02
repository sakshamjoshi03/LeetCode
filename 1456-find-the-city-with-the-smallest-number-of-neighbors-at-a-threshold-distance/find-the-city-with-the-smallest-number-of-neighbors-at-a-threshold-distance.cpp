class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : edges){
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        int city=-1;
        int minReach=INT_MAX;

        for(int i=0;i<n; i++){
            vector<int>dist(n,INT_MAX);
            priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
            dist[i] = 0;
            pq.push({0, i});
            while(!pq.empty()){
                int d = pq.top().first;
                int u = pq.top().second;
                pq.pop();
                if(d > dist[u]) continue;

                for(auto &p : adj[u]){
                    int v = p.first, w = p.second;
                    if(dist[v] > d + w){
                        dist[v] = d + w;
                        pq.push({dist[v], v});
                    }
                }
            }

            int count = 0;
            for(int j = 0; j < n; j++){
                if(i != j && dist[j] <= distanceThreshold) count++;
            }

            if(count <= minReach){
                minReach = count;
                city = i;
            }
        }

        return city;
    }
};