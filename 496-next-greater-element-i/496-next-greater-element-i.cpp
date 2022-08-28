class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        int n = nums2.size();
        st.push(nums2[n-1]);
        unordered_map<int,int> mpp;
        mpp[nums2[n-1]] = -1;
        for(int i = n-2; i >= 0; i--)
        {
            while(!st.empty() && nums2[i] >= st.top())
            {
                st.pop();
            }
            
            int elem = st.empty() ? -1 : st.top();
            mpp[nums2[i]] = elem;
            st.push(nums2[i]);
        }
        for(int i = 0; i < nums1.size(); i++)
        {
            ans.push_back(mpp[nums1[i]]);
        }
        return ans;
    }
};