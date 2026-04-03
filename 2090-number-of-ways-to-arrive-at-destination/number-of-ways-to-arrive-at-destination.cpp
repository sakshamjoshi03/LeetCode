class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int M = 1e9 + 7;

        vector<vector<pair<int,int>>> adj(n);
        for(auto &e : roads){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        vector<long long> ways(n,0);
        ways[0]=1;

        vector<long long> time(n,LLONG_MAX);   // fixed
        time[0]=0;

        priority_queue<
            pair<long long,int>,
            vector<pair<long long,int>>,
            greater<pair<long long,int>>
        > pq;

        pq.push({0,0});

        while(!pq.empty()){
            long long weight=pq.top().first;
            int vtx=pq.top().second;
            pq.pop();

            for(auto &ad : adj[vtx]){
                int adjvtx=ad.first;
                long long adjweight=ad.second;

                long long d=weight+adjweight;

                if(d<time[adjvtx]){
                    time[adjvtx]=d;
                    pq.push({d,adjvtx});
                    ways[adjvtx]=ways[vtx];
                }
                else if(d==time[adjvtx]){
                    ways[adjvtx]=(ways[adjvtx]+ways[vtx]) % M;
                }
            }
        }

        return ways[n-1] % M;   // moved outside loop
    }
};