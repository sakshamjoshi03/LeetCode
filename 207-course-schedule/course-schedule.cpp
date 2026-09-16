class Solution {
public:

    bool canFinish(int n, vector<vector<int>>& pre) {
                vector<vector<int>>adj(n);
                for(int i=0;i<pre.size();i++){
                int v=pre[i][0];
                int u=pre[i][1];
                adj[v].push_back(u);
                }
                vector<int>degree(n,0);
                for(int i=0;i<n;i++){
                    for(auto it : adj[i]){
                        degree[it]++;
                    }
                }
                queue<int>q;
                for(int i=0;i<n;i++){
                        if(degree[i]==0){
                            q.push(i);
                        }
                }
                vector<int>topo;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    topo.push_back(node);
                    for(auto neigh : adj[node]){
                        degree[neigh]--;
                        if(degree[neigh]==0) q.push(neigh);
                    }
                }
                if(topo.size()==n) return true;
                return false;
            }
        };