//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
	public:
	int solve(int index, vector<int> &arr, int target, vector<vector<int>> &dp)
	{
	    if(target == 0) return 0;
	    if(index == 0)
	    {
	        if(target % arr[0] == 0) return target / arr[0];
	        else return 1e9;
	    }
	    
	    if(dp[index][target] != -1) return dp[index][target];
	    
	    int not_pick = 0 + solve(index-1, arr, target, dp);
	    int pick = 1e9;
	    if(arr[index] <= target)
	    {
	        pick = 1 + solve(index, arr, target - arr[index], dp);
	    }
	    
	    return dp[index][target] = min(pick, not_pick);
	}
	int MinSquares(int n)
	{
	    // Code here
	    vector<int> temp;
	    for(int i = 1; i*i <= n; i++)
	    {
	        temp.push_back(i*i);
	    }
	    vector<vector<int>> dp(temp.size(), vector<int>(n+1,-1));
	    return solve(temp.size()-1, temp, n, dp);
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends