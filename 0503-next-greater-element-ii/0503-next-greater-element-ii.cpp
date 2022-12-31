class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            nums.push_back(nums[i]);
        }
        
        n = 2*n;
        stack<int> st;
        vector<int> ans;
        for(int i = n-1; i >= 0; i--)
        {
            while(!st.empty() && st.top() <= nums[i])
            {
                st.pop();
            }
            
            int elem = st.empty() ? -1 : st.top();
            ans.push_back(elem);
            st.push(nums[i]);
        }
        
        reverse(ans.begin(), ans.end());
        for(int i = n-1; i >= n/2; i--)
        {
            ans.pop_back();
        }
        
        return ans;
    }
};