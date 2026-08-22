class Solution {
public:
    void dfs(int n,int m,int i,int j,vector<vector<char>>& grid,vector<vector<bool>>&vis)
    {
        if(i>=n || j>=m || i<0 || j<0 ||grid[i][j]=='0' || vis[i][j] ) return;
        vis[i][j]=true;
        dfs(n,m,i+1,j,grid,vis);
        dfs(n,m,i,j+1,grid,vis);
        dfs(n,m,i-1,j,grid,vis);
        dfs(n,m,i,j-1,grid,vis);

    }
    int numIslands(vector<vector<char>>& grid) {
      int n=grid.size();
      int m=grid[0].size();
      int count=0;
      vector<vector<bool>>vis(n,vector<bool>(m,false));//mind n and m.
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]=='1'&&!vis[i][j]){
                dfs(n,m,i,j,grid,vis);
                count++;
            }
        }
      }
      return count;

    }
};