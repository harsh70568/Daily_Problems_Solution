// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        // Your code goes here
        int n = array1.size();
        int m = array2.size();
        if(n > m) return MedianOfArrays(array2,array1);
        int begin = 0;
        int end = n;
        while(begin <= end)
        {
            int i1 = (begin+end)/2;
            int i2 = (n+m+1)/2-i1;
            
            int min1 = (i1 == n) ? INT_MAX : array1[i1];
            int max1 = (i1 == 0) ? INT_MIN : array1[i1-1];
            
            int min2 = (i2 == m) ? INT_MAX : array2[i2];
            int max2 = (i2 == 0) ? INT_MIN : array2[i2-1];
            
            if((max1 <= min2) && (max2 <= min1))
            {
                if((n+m) % 2 == 0)
                {
                    return ((double) (max(max1,max2) + min(min1,min2))/2);
                }
                else
                {
                    return ((double) max(max1,max2));
                }
            }
            else if(max1 > min2) // left shift
            {
                end = i1-1;
            }
            else
            {
                begin = i1+1;
            }
        }
    
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends