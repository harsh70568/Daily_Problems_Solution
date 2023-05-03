class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2);
        
        set<int> st(nums2.begin(), nums2.end());
        vector<int> temp1;
        set<int> check1;
        for(auto it : nums1)
        {
            if(st.find(it) == st.end() && check1.find(it) == check1.end())
            {
                temp1.push_back(it);
                check1.insert(it);
            }
        }
        
        set<int> st2(nums1.begin(), nums1.end());
        vector<int> temp2;
        set<int> check2;
        for(auto it : nums2)
        {
            if(st2.find(it) == st2.end() && check2.find(it) == check2.end())
            {
                temp2.push_back(it);
                check2.insert(it);
            }
        }
        
        ans[0] = temp1;
        ans[1] = temp2;
        
        return ans;
    }
};