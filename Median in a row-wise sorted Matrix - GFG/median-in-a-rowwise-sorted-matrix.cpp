//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
int small_than(vector<int> &a, int x)
{
    int low = 0;
    int high = a.size()-1;
    
    while(low <= high)
    {
        int mid = (low + high) >> 1;
        if(a[mid] <= x)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    
    return low;
}
    int median(vector<vector<int>> &mat, int r, int c){
        int low = 1;
        int high = 2000;
        
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            int cnt = 0;
            for(int i = 0; i < r; i++)
            {
                cnt += small_than(mat[i], mid);
            }
            
            if(cnt <= (r*c)/2)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return low;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends