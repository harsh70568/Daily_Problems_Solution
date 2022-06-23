class Solution {
public:
    string frequencySort(string s) {
        string temp = "";
        unordered_map<char,int> mpp;
        for(int i = 0; i < s.size(); i++)
        {
            mpp[s[i]]++;
        }
        
        vector<pair<int,char>> ans;
        for(auto it : mpp)
        {
            ans.push_back({it.second,it.first});
        }
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        for(auto it : ans)
        {
            while(it.first--)
            {
                temp += it.second;
            }
        }
        return temp;
    }
};