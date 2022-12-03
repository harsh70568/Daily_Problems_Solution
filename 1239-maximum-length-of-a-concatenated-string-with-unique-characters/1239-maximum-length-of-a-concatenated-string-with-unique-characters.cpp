class Solution {
public:
    bool length(string &s)
    {
        unordered_map<char, int> mpp;
        for(auto it : s)
        {
            mpp[it]++;
        }
        
        return mpp.size() == s.size();
    }
    bool check(string s, string temp)
    {
        unordered_map<char, int> mpp;
        for(auto it : temp)
        {
            mpp[it]++;
        }
        
        for(auto it : s)
        {
            if(mpp.find(it) != mpp.end()) return false;
        }
        
        return true;
    }

    int solve(int index, vector<string> &arr, string temp)
    {
        if(index >= arr.size()) return 0;
        
        int not_pick = 0 + solve(index+1, arr, temp);
        int pick = INT_MIN;
        if(check(arr[index], temp) && length(arr[index]))
        {
            pick = arr[index].length() + solve(index+1, arr, temp + arr[index]);
        }
        
        return max(pick, not_pick);
    }
    int maxLength(vector<string>& arr) {
        return solve(0, arr, "");
    }
};