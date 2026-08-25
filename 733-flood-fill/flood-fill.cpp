class Solution {
public:
    void dfs(vector<vector<int>>& image,  int sr, int sc , vector<vector<bool>>&vis ,int n , int m ,int color, int original){
        if(sr>=n || sc>=m || sr<0 || sc<0 || vis[sr][sc] || image[sr][sc] != original ) return;
        vis[sr][sc]=true;
        image[sr][sc]=color;
        dfs(image,sr+1,sc,vis,n,m,color,original);
        dfs(image,sr-1,sc,vis,n,m,color,original);
        dfs(image,sr,sc+1,vis,n,m,color,original);
        dfs(image,sr,sc-1,vis,n,m,color,original);
        

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n=image.size();
        int m=image[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int original=image[sr][sc];
        if(original==color)
            return image;
        dfs(image,sr,sc,vis,n,m,color,original);
        return image;
    }
};