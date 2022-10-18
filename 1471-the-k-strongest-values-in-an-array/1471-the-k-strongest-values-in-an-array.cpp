class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int,int> &b)
    {
        if(a.first == b.first) return a.second > b.second; 
        return a.first > b.first;
    }
    vector<int> getStrongest(vector<int>& arr, int k) {
        vector<int> ans;
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int median = arr[(n-1)/2];
        //cout<<median<<endl;
        vector<pair<int,int>> temp;
        
        for(int i = 0; i < arr.size(); i++)
        {
            temp.push_back({abs(arr[i] - median), arr[i]});
        }
        
        sort(temp.begin(), temp.end(), cmp);
        
        // for(int i = 0; i < temp.size(); i++)
        // {
        //     cout<<temp[i].first<<" "<<temp[i].second;
        // }
        for(int i = 0; i < temp.size(); i++)
        {
            if(k == 0) break;
            ans.push_back(temp[i].second);
            k--;
        }
        
        return ans;
    }
};