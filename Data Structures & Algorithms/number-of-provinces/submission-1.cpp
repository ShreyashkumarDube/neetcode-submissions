class Solution {
public:
    vector<int> parent, rank;

    int find(int x){
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y){
        int x_par = find(x);
        int y_par = find(y);

        if(rank[x_par] > rank[y_par]){
            parent[y_par] = x_par;
        }
        else if(rank[x_par] < rank[y_par]){
            parent[x_par] = y_par;
        }
        else{
            parent[x_par] = y_par;
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        parent.resize(n);
        rank.resize(n, 0);

        int components = n;

        for(int i=0; i<n; i++){

            parent[i] = i;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]){
                    if(find(i) != find(j)){
                        Union(i, j);
                    components--;
                    }
                }
            }
        }
        return components;
    }
};