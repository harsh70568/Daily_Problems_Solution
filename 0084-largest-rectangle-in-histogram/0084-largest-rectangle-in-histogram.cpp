class Solution {
public:
    vector<int> PSE(vector<int> heights)
    {
        int n = heights.size();
        reverse(heights.begin(), heights.end());
        stack<pair<int, int>> st;
        st.push({heights[n-1], n-1});
        vector<int> ans;
        ans.push_back(-1);
        
        for(int i = n-2; i >= 0; i--)
        {
            while(!st.empty() && heights[i] <= st.top().first)
            {
                st.pop();
            }
            
            int idx = st.empty() ? -1 : n - 1 - st.top().second;
            ans.push_back(idx);
            st.push({heights[i], i});
        }
        
        return ans;
    }
    vector<int> NSE(vector<int> heights)
    {
        int n = heights.size();
        stack<pair<int, int>> st;
        vector<int> ans;
        ans.push_back(-1);
        st.push({heights[n-1], n-1});
        
        for(int i = n-2; i >= 0; i--)
        {
            while(!st.empty() && heights[i] <= st.top().first)
            {
                st.pop();
            }
            
            int idx = st.empty() ? n : st.top().second;
            ans.push_back(idx);
            st.push({heights[i], i});
        }
        
        reverse(ans.begin(), ans.end());
        return  ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> next_smaller = NSE(heights);
        vector<int> prev_smaller = PSE(heights);
        
//         for(auto it : next_smaller) cout<<it<<" ";
//         cout<<endl;
//         for(auto it : prev_smaller) cout<<it<<" ";
//         cout<<endl;
        
        int max_area = -1;
        for(int i = 1; i < n-1; i++)
        {
            int length = heights[i];
            int breadth = next_smaller[i] - i;
            if(prev_smaller[i] == -1) breadth += i;
            else breadth += (i - prev_smaller[i] - 1);
            //cout<<length<<" "<<breadth<<endl;
            max_area = max(max_area, length*breadth);
        }
        
        max_area = max(max_area, heights[0]*next_smaller[0]);
        max_area = max(max_area, heights[n-1]*(n - 1 - prev_smaller[n-1]));
        return max_area;
    }
};