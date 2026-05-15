class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indeg(n+1, 0);
        vector<int> outdeg(n+1, 0);

        for(auto i: trust){
            int a = i[0];
            int b = i[1];

            outdeg[a]++;
            indeg[b]++;
        }

        for(int i=1; i<=n; i++){
            if(outdeg[i]==0 && indeg[i] == n-1){
                return i;
            }
        }
        return -1;
    }
};