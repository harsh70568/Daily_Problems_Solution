// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        // Code here
        unordered_map<int,int> mpp;
        vector<int> ans;
        vector<pair<int,int>> temp;
        
        for(int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        
        for(auto it : mpp)
        {
            temp.push_back({it.second,it.first});
        }
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        
        for(auto it : temp)
        {
            if(k == 0) return ans;
            ans.push_back(it.second);
            k--;
        }
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends