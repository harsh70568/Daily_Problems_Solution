class Solution {
public:
    static bool cmp(pair<int, string> &a, pair<int, string> &b)
    {
        if(a.first == b.first) return a.second < b.second;
        return a.first > b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mpp;
        
        for(int i = 0; i < words.size(); i++)
        {
            mpp[words[i]]++;
        }
        
        vector<pair<int, string>> temp;
        
        for(auto it : mpp)
        {
            temp.push_back({it.second, it.first});
        }
        
        sort(temp.begin(), temp.end(), cmp);
        
        for(int i = 0; i < temp.size(); i++)
        {
            if(k == 0) break;
            ans.push_back(temp[i].second);
            k--;
        }
        
        return ans;
    }
};