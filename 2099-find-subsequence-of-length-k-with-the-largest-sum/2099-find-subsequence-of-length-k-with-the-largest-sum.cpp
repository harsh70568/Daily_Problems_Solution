class Solution {
public:
    bool static cmp(pair<int,int> &a, pair<int,int> &b)
    {
        return a.second < b.second;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        vector<pair<int,int>> temp;
        for(int i = 0; i < nums.size(); i++)
        {
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        vector<int> ans;
        
        
        for(int i=  0; i < v.size(); i++)
        {
            if(k == 0) break;
            temp.push_back(v[i]);
            k--;
        }
        
        sort(temp.begin(),temp.end(),cmp);
        
        for(auto it : temp)
        {
            ans.push_back(it.first);
        }
        
        return ans;
        
    }
};