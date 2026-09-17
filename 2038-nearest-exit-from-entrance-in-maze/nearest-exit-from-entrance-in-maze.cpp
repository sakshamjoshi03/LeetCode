class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';//to avoid exit from entrace 
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            steps++;
            while(size--){
                int row=q.front().first;
                int col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++) {
                    int nr=row + dr[i];
                    int nc=col + dc[i];
                    if(nr >= 0 && nr < n &&
                       nc >= 0 && nc < m &&
                       maze[nr][nc] == '.') {
                        // Check whether it is an exit
                        if(nr == 0 || nr == n-1 ||
                           nc == 0 || nc == m-1) {
                            return steps;
                        }
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }
        }
        return -1;
    }
};