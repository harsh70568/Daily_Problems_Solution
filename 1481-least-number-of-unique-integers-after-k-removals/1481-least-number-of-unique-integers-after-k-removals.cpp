class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int,int> &b)
    {
        return a.first < b.first;
    }
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> mpp;
        for(auto it : arr)
        {
            mpp[it]++;
        }
        
        vector<pair<int,int>> ans;
        for(auto it : mpp)
        {
            ans.push_back({it.second,it.first});
        }
        
        sort(ans.begin(), ans.end(), cmp);
        vector<int> res;
        for(int i = 0; i < ans.size(); i++)
        {
            //if(k == 0) break;
            while(ans[i].first != 0 && k)
            {
                ans[i].first--;
                k--;
            }
            if(ans[i].first != 0) res.push_back(ans[i].second);
        }
        
        return res.size();
        
    }
};