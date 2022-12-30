class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> ans;
        vector<int> pre(n);
        
        pre[0] = arr[0];
        for(int i = 1; i < n; i++)
        {
            pre[i] = pre[i-1] ^ arr[i];
        }
        
        int sum = 0;
        for(int i = 0; i < queries.size(); i++)
        {
            int left = queries[i][0];
            int right = queries[i][1];
            
            if(left == 0) ans.push_back(pre[right]);
            //else if(left == 1) ans.push_back(pre[right] ^ pre[0]);
            else ans.push_back(pre[right] ^ pre[left-1]);
            
        }
        
        return ans;
    }
};