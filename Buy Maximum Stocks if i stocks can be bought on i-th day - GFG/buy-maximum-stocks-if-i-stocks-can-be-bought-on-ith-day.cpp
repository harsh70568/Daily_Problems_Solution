//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        vector<pair<int, int>> temp;
        for(int i = 0; i < n; i++)
        {
            temp.push_back({price[i], i+1});
        }
        
        sort(temp.begin(), temp.end());
        
        int cnt = 0;
        for(int i = 0; i < temp.size(); i++)
        {
            int val = min(temp[i].second, k / temp[i].first);
            cnt += val;
            k -= val*temp[i].first;
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends