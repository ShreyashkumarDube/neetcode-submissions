class Solution {
public:

    vector<int> rank, parent;

    int find(int x){
        if(parent[x] ==x) return x;

        return parent[x] = find(parent[x]);
    }

    void Union (int x, int y) {
            int x_parent = find(x);
            int y_parent = find(y);

            if (x_parent == y_parent) 
                return;

            if(rank[x_parent] > rank[y_parent]) {
                parent[y_parent] = x_parent;
            } else if(rank[x_parent] < rank[y_parent]) {
                parent[x_parent] = y_parent;
            } else {
                parent[x_parent] = y_parent;
                rank[y_parent]++;
            }
        }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
       int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1, 0);

        for(int i=0; i<n; i++) parent[i] = i;

        unordered_map<int, vector<int>> adj;
        int components = n;
        for(auto i: edges){
            int a = i[0];
            int b = i[1];

            int a_par = find(a);
            int b_par = find(b);

            if(a_par != b_par){
                Union(a, b);
                components--;
            }
            else{
                return {a, b};
            }
        }
        return {};
    }
};
