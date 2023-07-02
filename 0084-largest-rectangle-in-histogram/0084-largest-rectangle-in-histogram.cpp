class Solution {
public:
    vector<int> prev_smaller(vector<int> heights)
    {
        reverse(heights.begin(), heights.end());
        stack<pair<int, int>> st;
        vector<int> ans;
        
        for(int i = heights.size()-1; i >= 0; i--)
        {
            while(!st.empty() && heights[i] <= st.top().first) st.pop();
            
            int val = st.empty() ? heights.size() - i : st.top().second - i;
            ans.push_back(val);
            st.push({heights[i], i});
        }
        
        return ans;
        
    }
    vector<int> next_smaller(vector<int> &heights)
    {
        stack<pair<int, int>> st;
        vector<int> ans;
        for(int i = heights.size()-1; i >= 0; i--)
        {
            while(!st.empty() && heights[i] <= st.top().first) st.pop();
            
            int val = st.empty() ? heights.size() - i : st.top().second - i;
            ans.push_back(val);
            st.push({heights[i], i});
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> next_small = next_smaller(heights);
        vector<int> prev_small = prev_smaller(heights);
        //for(auto it : prev_small) cout<<it<<" ";
        

        int max_area = 0;
        for(int i = 0; i < heights.size(); i++)
        {
            int area = (heights[i]*(next_small[i] + prev_small[i] - 1));
            max_area = max(max_area, area);
        }
        return max_area;
    }
};