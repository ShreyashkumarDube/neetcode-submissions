class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        for(auto i: times){
            adj[i[0]].push_back({i[1], i[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> ans(n+1, INT_MAX);

        ans[k] = 0;

        pq.push({0, k});

        while(!pq.empty()){
            int dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto i: adj[node]){
                int adjnode = i.first;
                int time = i.second;
                    if(dist + time < ans[adjnode]){
                        ans[adjnode] = dist+time;
                        pq.push({dist + time, adjnode});
                    }
            }
        }

        int result = INT_MIN;

        for(int i=1; i<=n; i++){
            result = max(result, ans[i]);
        }
        
        return result == INT_MAX ? -1 : result;
    }
};
