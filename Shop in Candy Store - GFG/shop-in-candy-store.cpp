//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int n, int K)
    {
        // Write Your Code here
        sort(candies, candies+n);
        
        int i = 0;
        int j = n-1;
        
        int min_amount = 0;
        while(i <= j)
        {
            min_amount += (candies[i]);
            int val = K;
            while(val--)
            {
                j--;
            }
            i++;
        }
        
        i = 0;
        j = n-1;
        int max_amount = 0;
        while(i <= j)
        {
            max_amount += candies[j];
            int val = K;
            while(val--)
            {
                i++;
            }
            j--;
        }
        
        return {min_amount, max_amount};
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}
// } Driver Code Ends