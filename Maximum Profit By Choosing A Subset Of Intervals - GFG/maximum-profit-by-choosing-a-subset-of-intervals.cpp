//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int solve(int index, vector<vector<int>> &intervals, vector<int> &temp, vector<int> &dp)
  {
      if(index >= intervals.size()) return 0;
      
      if(dp[index] != -1) return dp[index];
      
      auto next_idx = lower_bound(temp.begin(), temp.end(), intervals[index][1]) - temp.begin();
      int not_pick = solve(index+1, intervals, temp, dp);
      int pick = intervals[index][2] + solve(next_idx, intervals, temp, dp);
      
      return dp[index] = max(pick, not_pick);
  }
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        // Write your code here.
        sort(intervals.begin(), intervals.end());
        vector<int> temp;
        vector<int> dp(n+1,-1);
        for(auto it : intervals)
        {
            temp.push_back(it[0]);
        }
        
        return solve(0, intervals, temp, dp);
        
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends