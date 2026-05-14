class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> indeg(n, 0);

        unordered_map<int, vector<int>> adj;

        for(auto i: pre){
            indeg[i[1]]++;
            adj[i[0]].push_back(i[1]);
        }

        queue<int> q;

        for(int i=0; i<n; i++){
            if(indeg[i]==0) q.push(i);
        }

        vector<int> ans;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto i: adj[node]){
                indeg[i]--;
                if(indeg[i]==0) q.push(i);
            }
        }

        if(ans.size() != n) return {};
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
