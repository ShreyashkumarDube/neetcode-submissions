class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0){
                    q.push({i, j});
                }
            }
        }

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            for(int i=0; i<4; i++){
                int nr= r + dx[i];
                int nc = c+dy[i];

                if(nr<0 || nr>=n || nc<0 || nc>= m || grid[nr][nc]!=2147483647) continue;

                grid[nr][nc] = grid[r][c]+1;
                q.push({nr, nc});
            }
        }
    }
};
