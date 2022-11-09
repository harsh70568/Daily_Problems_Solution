class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans;
        int n = temperatures.size();
        stack<pair<int, int>> st;
        st.push({temperatures[n-1], n-1});
        ans.push_back(0);
        
        for(int i = n-2; i >= 0; i--)
        {
            while(!st.empty() && temperatures[i] >= st.top().first)
            {
                st.pop();
            }
            
            int elem = st.empty() ? 0 : st.top().second - i;
            ans.push_back(elem);
            st.push({temperatures[i], i});
        }
        
        
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};