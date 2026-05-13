class Solution {
public:

    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid){
        int n= grid.size();
        int m =grid[0].size();
        vis[i][j] = 1;
        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for(int k=0; k<4; k++){
            int nx = i+dx[k];
            int ny = j+ dy[k];

            if(nx<n && nx>=0 && ny>=0 && ny<m && !vis[nx][ny] && grid[nx][ny]=='1'){
                dfs(nx, ny, vis, grid);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;

        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    ans++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return ans;
    }
};
