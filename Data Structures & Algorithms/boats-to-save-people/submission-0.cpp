class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int l = 0;
        int r = people.size() - 1;
        while (l <= r) {
            int rem = limit - people[r];
            r--;
            ans++;
            if (l <= r && rem >= people[l]) {
                l++;
            }
        }
        return ans;
    }
};