//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        //code here.
        map<string, int> mpp;
        for(int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
            //maxi = max(maxi, mpp[arr[i]]);
        }
        
        vector<pair<int, string>> temp;
        for(auto it : mpp)
        {
            temp.push_back({it.second, it.first});
        }
        
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        
        return temp[1].second;
        
        
        
        
        
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends