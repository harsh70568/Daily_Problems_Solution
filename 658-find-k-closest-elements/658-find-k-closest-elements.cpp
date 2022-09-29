class Solution {
public:
    static bool cmp(pair<int,int> &a, pair<int,int> &b)
    {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> res;
        vector<pair<int,int>> ans;
        
        for(int i = 0; i < arr.size(); i++)
        {
            ans.push_back({arr[i], abs(arr[i] - x)});
        }
        
        sort(ans.begin(),ans.end(),cmp);
        int n = ans.size();
        int size = min(k,n);
        for(int i = 0; i < size; i++)
        {
            res.push_back(ans[i].first);
        }
        
        sort(res.begin(),res.end());
        
        return res;
    }
};