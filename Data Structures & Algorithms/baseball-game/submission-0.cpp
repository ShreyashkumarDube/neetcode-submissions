class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        int ans = 0;

        for(auto i: operations){
            if(i=="+"){
                int top = st.top();
                st.pop();
                int tmp = top + st.top();
                st.push(top);
                st.push(tmp);
                ans += tmp;
            }
            else if (i == "D") {
                st.push(2 * st.top());
                ans += st.top();
            } else if (i == "C") {
                ans -= st.top();
                st.pop();
            } else {
                st.push(stoi(i));
                ans += st.top();
            }
        }
        return ans;
        }
    
};