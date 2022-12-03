class Solution {
public:
    static bool cmp(pair<int, char> &a, pair<int, char> &b)
    {
        return a.first > b.first;
    }
    string frequencySort(string s) {
        unordered_map<char, int> mpp;
        for(auto it : s)
        {
            mpp[it]++;
        }
        
        vector<pair<int, char>> ans;
        
        for(auto it : mpp)
        {
            ans.push_back({it.second, it.first});
        }
        
        
        sort(ans.begin(), ans.end(), cmp);
        string temp = "";
        for(int i = 0; i < ans.size(); i++)
        {
            while(ans[i].first)
            {
                temp += ans[i].second;
                ans[i].first--;
            }
        }
        
        return temp;
    }
};