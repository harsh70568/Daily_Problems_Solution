class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
       multiset<int> ans(nums1.begin(), nums1.end());
        
        vector<int> temp;
        for(int i = 0; i < nums1.size(); i++)
        {
            auto it = ans.upper_bound(nums2[i]);
            
            if(it == ans.end())
            {
                temp.push_back(*ans.begin());
                ans.erase(ans.begin());
            }
            else
            {
                temp.push_back(*it);
                ans.erase(it);
            }
        }
        
        return temp;
        
        
    }
};