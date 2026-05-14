class Solution {
public:
int n, m;

    void dfs(int r, int c, vector<vector<int>> &heights, vector<vector<int>> &visited){
        visited[r][c] = 1;

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, -1, 0, 1};

        for(int i=0; i<4; i++){
            int nr = r + dx[i];
            int nc = c+ dy[i];

            if(nr < n && nr>=0 && nc<m && nc>= 0 && !visited[nr][nc] && heights[nr][nc]>= heights[r][c]){
                dfs(nr, nc, heights, visited);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();

        vector<vector<int>> pacific(n, vector<int>(m, 0));
        vector<vector<int>> atlantic(n, vector<int>(m, 0));

        //Pacific
        for(int i=0; i<n; i++){
            dfs(i, 0, heights, pacific);
        }
        for(int j=0; j<m; j++){
            dfs(0, j, heights, pacific);
        }

        //Atlantic
        for(int i=0; i<n; i++){
            dfs(i, m-1, heights, atlantic);
        }
        for(int j=0; j<m; j++){
            dfs(n-1, j, heights, atlantic);
        }

        vector<vector<int>> ans;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(atlantic[i][j] && pacific[i][j]){
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};

