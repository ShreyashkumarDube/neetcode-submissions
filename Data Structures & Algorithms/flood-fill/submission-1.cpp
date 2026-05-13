class Solution {
public:

    int n, m;

    void dfs(vector<vector<int>> &image, int r, int c, int ori, int col){
        if(r<0 || r>=n || c<0 || c>=m || image[r][c] != ori) return;

        image[r][c]= col;
        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        for(int i=0; i<4; i++){
            dfs(image, r+dx[i], c+dy[i], ori, col);
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int starting = image[sr][sc];
        if(starting == color) return image;
        n = image.size();
        m = image[0].size();

        dfs(image, sr, sc, starting, color);
        return image;

    }
};