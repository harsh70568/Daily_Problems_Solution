class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> ans;
        ans.push_back(0);
        
        int n = temp.size();
        stack<pair<int, int>> st;
        st.push({temp[n-1], n-1});
        for(int i = n-2; i >= 0; i--)
        {
            while(!st.empty() && temp[i] >= st.top().first)
            {
                st.pop();
            }
            
            int val = st.empty() ? 0 : st.top().second - i;
            ans.push_back(val);
            
            st.push({temp[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};