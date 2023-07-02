class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> st;
        map<int, int> mpp;
        for(int i = nums2.size()-1; i >= 0; i--)
        {
            while(!st.empty() && nums2[i] >= st.top()) st.pop();
            
            int val = st.empty() ? -1 : st.top();
            mpp[nums2[i]] = val;
            st.push(nums2[i]);
        }
        
        for(int i = 0; i < nums1.size(); i++) nums1[i] = mpp[nums1[i]];
        
        return nums1;
    }
};