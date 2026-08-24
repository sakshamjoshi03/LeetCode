class Solution {
public:
    void dfs(vector<vector<int>>& grid,int src,vector<bool>&vis){
        vis[src]=true;
        for(int j=0;j<grid.size();j++){
            if(!vis[j] && grid[src][j]){
                dfs(grid,j,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& grid) {
        int n=grid.size();
        int count=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
                if(!vis[i]){
                    dfs(grid,i,vis);
                    count++;
                }
            }
        return count;
    }
};