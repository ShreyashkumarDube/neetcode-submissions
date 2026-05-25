class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0,0});

        int dx[] = {1, 0, -1, 0};
        int dy[] = {0, 1, 0, -1};

        while(!pq.empty()){
            auto i = pq.top();
            pq.pop();

            int dif = i[0];
            int r = i[1];
            int c = i[2];

            if(r == n-1 && c == m-1) return dif;
            if(dist[r][c] < dif) continue;

            for(int j=0; j<4; j++){
                int nr= r + dx[j];
                int nc = c+dy[j];

                if(nr>=n || nr<0 || nc<0 || nc>=m) continue;

                int tmp = max(dif, abs(heights[r][c]-heights[nr][nc]));

                if(tmp < dist[nr][nc]){
                    dist[nr][nc] = tmp;
                    pq.push({tmp, nr, nc});
                }
            }
        }
    return -1;

    }
};