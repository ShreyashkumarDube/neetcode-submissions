class Solution {
public:

    void dfs(int node, vector<int> &vis, unordered_map<int, vector<int>> &adj){
        vis[node] = 1;

        for(auto i: adj[node]){
            if(!vis[i]){
                dfs(i, vis, adj);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;

        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        int ans = 0;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, adj);
                ans++;
            }
        }

        return ans;
    }
};
