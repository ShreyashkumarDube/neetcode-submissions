class Solution {
public:

    void dfs(unordered_map<string, vector<pair<string, double>>> &adj, string src, string dst, unordered_set<string>& vis, double prod, double &ans) {
        if(vis.find(src) != vis.end()){
            return;
        }

        vis.insert(src);

        if(src == dst){
            ans = prod;
            return;
        }

        for(auto i: adj[src]){
            auto v = i.first;
            double val = i.second;

            dfs(adj, v, dst, vis, prod*val, ans);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n= equations.size();

        unordered_map<string, vector<pair<string, double>>> adj;

        for(int i=0; i<n; i++){
            auto a = equations[i][0];
            auto b = equations[i][1];
            auto val = values[i];

            adj[a].push_back({b, val});
            adj[b].push_back({a, 1.0/val});
        }

        vector<double> result;

        for(auto i: queries){
            auto src = i[0];
            auto dst = i[1];

            auto ans = -1.0;
            auto prod = 1.0;

            if(adj.find(src) != adj.end()){
                unordered_set<string> vis;
                dfs(adj, src, dst, vis, prod, ans);
            }
            result.push_back(ans);
        }
        return result;
    }
};