// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool is_possible(int A[], int n, int m, int mid)
    {
        int students_count = 1;
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(sum+A[i] <= mid)
            {
                sum += A[i];
            }
            else
            {
                students_count++;
                if(students_count > m || A[i] > mid)
                {
                    return false;
                }
                sum = A[i];
            }
        }
        return true;
    }
    int findPages(int A[], int N, int M) 
    {
        //code here
        int start = 0;
        int sum = 0;
        for(int i = 0; i < N; i++)
        {
            sum += A[i];
        }
        int end = sum;
        int ans = -1;
        
        while(start <= end)
        {
            int mid = (start+end)/2;
            
            if(is_possible(A,N,M,mid))
            {
                ans = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends