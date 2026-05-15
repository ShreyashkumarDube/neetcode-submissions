class Solution {
public:

    bool dfs(int u, int v, unordered_map<int, vector<int>> &adj, vector<int> &vis){
        if(u == v) return true;
        vis[u]= 1;
        for(auto i: adj[u]){
            if(!vis[i]){
                if(dfs(i, v, adj, vis)) return true;
            }
        }
        return false;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();

        unordered_map<int, vector<int>> adj;

        for(auto i: edges){
            int a= i[0];
            int b = i[1];

            vector<int> vis(n+1, 0);

            if(dfs(a, b, adj, vis)){
                return {a,b};
            }
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        return {};
    }
};
