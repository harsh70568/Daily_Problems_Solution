class Solution {
public:
   static bool myCompare(pair<int, int> &a, pair<int, int> &b)
    {
        if(a.second== b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        vector<int> ans;
        vector<pair<int, int>> temp;
        for(int i=0; i< arr.size(); i++)
        {
            temp.push_back({arr[i], abs(arr[i]- x)});
        }
        sort(temp.begin(), temp.end(), myCompare);
        int i=0;
        while(k--)
        {
            ans.push_back(temp[i++].first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};