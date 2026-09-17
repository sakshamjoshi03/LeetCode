class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1)return -1;
        queue<pair<int,int>>q;//stores i,j
        q.push({0,0});
        vector<vector<int>>dist(n,vector<int>(n,9999));
        dist[0][0]=1;
        int dr[] = {-1,-1,-1, 0,0, 1,1,1};
        int dc[] = {-1, 0, 1,-1,1,-1,0,1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int ni=row+dr[i];
                int nj=col+dc[i];
                if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==0){
                    if(dist[row][col]+1<dist[ni][nj]){
                        dist[ni][nj]=dist[row][col]+1;
                        q.push({ni,nj});
                    }

                }
            }
        }
            if(dist[n-1][n-1]==9999) return -1;
            return dist[n-1][n-1];



    }
};