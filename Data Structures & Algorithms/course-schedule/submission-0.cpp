class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> indeg(n, 0);
        vector<vector<int>> adj(n);

        for(auto i: pre){
            indeg[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(indeg[i] == 0) q.push(i);
        }

        int total = 0;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            total++;

            for(auto i: adj[node]){
                indeg[i]--;
                if(indeg[i]==0) q.push(i);
            }

        }
        return total == n;
    }
};
