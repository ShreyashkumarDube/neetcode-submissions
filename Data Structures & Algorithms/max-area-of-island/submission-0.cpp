class Solution {
public:
int n, m;

    int dfs(int r, int c, vector<vector<int>> &vis, vector<vector<int>> &grid){
        if(r<0 || c<0 || r>=n || c>=m || grid[r][c] == 0 || vis[r][c]) return 0;

        vis[r][c] = 1;
        int ans = 1;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};
        for(int i=0; i<4; i++){
            int nx = r + dx[i];
            int ny = c + dy[i];

            ans += dfs(nx, ny, vis, grid);
        }
        return ans;

    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));

        int ans = 0;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    ans = max(ans, dfs(i, j, vis,grid));
                }
            }
        }
        return ans;
    }
};
