class Solution {
public:
    void solve(vector<int> &arr, vector<vector<int>> &ans, vector<int> &temp, int k, int index)
    {
        if(index >= arr.size())
        {
            if(temp.size() == k)
            {
                ans.push_back(temp);
            }
            return;
        }
        
        temp.push_back(arr[index]);
        solve(arr,ans,temp,k,index+1);
        temp.pop_back();
        solve(arr,ans,temp,k,index+1);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            arr[i] = i+1;
        }
        vector<vector<int>> ans;
        vector<int> temp;
        solve(arr,ans,temp,k,0);
        return ans;
        
    }
};