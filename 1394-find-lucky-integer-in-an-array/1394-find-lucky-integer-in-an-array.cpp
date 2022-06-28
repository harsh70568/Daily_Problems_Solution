class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i = 0; i < arr.size(); i++)
        {
            mpp[arr[i]]++;
        }
        
        vector<pair<int,int>> ans;
        for(auto it : mpp)
        {
            ans.push_back({it.second,it.first});
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        for(auto it : ans)
        {
            if(it.first == it.second)
            {
                return it.first;
            }
        }
        return -1;
    }
};