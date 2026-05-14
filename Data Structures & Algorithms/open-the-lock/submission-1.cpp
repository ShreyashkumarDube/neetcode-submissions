class Solution {
public:
    vector<string> fun(string tmp){
        vector<string> ans;

        for (int i = 0; i < 4; i++) {
            string up = tmp;
            string down = tmp;

            up[i] = (up[i] - '0' + 1) % 10 + '0';
            down[i] = (down[i] - '0' - 1 + 10) % 10 + '0';

            ans.push_back(up);
            ans.push_back(down);
        }

        return ans;
        
    }


    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visit(deadends.begin(), deadends.end());

        if(visit.count("0000")) return -1;
        
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        visit.insert("0000");

        while(!q.empty()){
            string tmp = q.front().first;
            int cnt = q.front().second;

            q.pop();

            if(tmp== target) return cnt;

            for(auto i: fun(tmp)){
                if(!visit.count(i)){
                    visit.insert(i);
                    q.push({i, cnt+1});
                }
            }
        }
        return -1;
    }
};