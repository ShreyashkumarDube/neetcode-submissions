class Solution {
public:

    int n, m;
    vector<vector<int>> visited;

    void dfs(int r, int c, vector<vector<int>> &grid){
        visited[r][c] = 1;

        grid[r][c] = 0;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            int nr = r+ dx[i];
            int nc = c+ dy[i];

            if(nr<n && nr>=0 && nc>=0 && nc<m && !visited[nr][nc] && grid[nr][nc] == 1){
                dfs(nr, nc, grid);
            }
        }
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        visited.resize(n, vector<int>(m, 0));

        //All 4 boundaries:

        //left
        for(int i=0; i<n; i++){
            if(!visited[i][0] && grid[i][0]==1){
                dfs(i, 0, grid);
            }
        }
        //right
         for(int i=0; i<n; i++){
            if(!visited[i][m-1] && grid[i][m-1]==1){
                dfs(i, m-1, grid);
            }
        }

        //top
        for(int j=0; j<m; j++){
            if(!visited[0][j] && grid[0][j]==1){
                dfs(0, j, grid);
            }
        }
        //down
          for(int j=0; j<m; j++){
            if(!visited[n-1][j] && grid[n-1][j]==1){
                dfs(n-1, j, grid);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    ans++;
                }
            }
        }

        return ans;
    }
};