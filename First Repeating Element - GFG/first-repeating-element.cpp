// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++

class Solution {
  public:
    // Function to return the position of the first repeating element.
    int firstRepeated(int arr[], int n) {
        // code here
        unordered_map<int,int> mpp;
        unordered_map<int,int> index;
        for(int i = 0; i < n; i++)
        {
            mpp[arr[i]]++;
        }
        
        for(int i = n-1; i >= 0; i--)
        {
            index[arr[i]] = i+1;
        }
        int min_index = INT_MAX;
        for(auto it : mpp)
        {
            if(it.second > 1)
            {
                int curr_index = index[it.first];
                min_index = min(min_index,curr_index);
            }
        }
        if(min_index == INT_MAX) return -1;
        return min_index;
    }
};

// { Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; ++i) cin >> arr[i];
        Solution ob;
        cout << ob.firstRepeated(arr, n) << "\n";
    }

    return 0;
}
  // } Driver Code Ends