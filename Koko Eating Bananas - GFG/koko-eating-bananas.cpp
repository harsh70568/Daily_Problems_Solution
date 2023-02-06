//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  long long is_possible(vector<int> &piles, int mid)
  {
      long long t_h = 0;
      for(int i = 0; i < piles.size(); i++)
      {
          t_h += (piles[i] / mid);
          if(piles[i] % mid != 0) t_h++;
      }
      
      return t_h;
  }
    int Solve(int N, vector<int>& piles, int H) {
        // Code here
        int maxi = -1;
        for(auto it : piles) maxi = max(maxi, it);
        
        int low = 1;
        int high = maxi;
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(piles, mid) <= H)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends