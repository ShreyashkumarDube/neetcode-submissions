class Solution {
public:

    bool dfs(int node, int parent, unordered_set<int> &vis, unordered_map<int, vector<int>> & adj){
        if(vis.count(node)) return false;

        vis.insert(node);

        for(auto i: adj[node]){
            if(i== parent) continue;
            if(!dfs(i, node, vis, adj)) return false;
        }
        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1) return false;

        unordered_map<int, vector<int>> adj;

        for(auto i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        unordered_set<int> vis;

        if(!dfs(0, -1, vis, adj)) return false;

        return vis.size() == n;
    }
};
