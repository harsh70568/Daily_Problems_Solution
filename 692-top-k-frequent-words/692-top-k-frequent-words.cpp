class Solution {
public:
    static bool cmp(pair<int,string> &a, pair<int,string> &b)
    {
        if(a.first == b.first) return a.second < b.second;
        
        return a.first > b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        unordered_map<string,int> mpp;
        for(auto it : words)
        {
            mpp[it]++;
        }
        
        vector<pair<int,string>> temp;
        for(auto it : mpp)
        {
            temp.push_back({it.second,it.first});
        }
        
        sort(temp.begin(),temp.end(),cmp);
        
        for(auto it : temp)
        {
            if(k == 0) return ans;
            ans.push_back(it.second);
            k--;
        }
        return ans;
    }
};