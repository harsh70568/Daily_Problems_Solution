class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) nums.push_back(nums[i]);
        
        vector<int> ans;
        stack<int> st;
        for(int i = 2*n-1; i >= 0; i--)
        {
            while(!st.empty() && nums[i] >= st.top()) st.pop();
            
            int val = st.empty() ? -1 : st.top();
            ans.push_back(val);
            st.push(nums[i]);
        }
        
        
        reverse(ans.begin(), ans.end());
        for(int i = 0; i < n; i++) ans.pop_back();
        return ans;
    }
};