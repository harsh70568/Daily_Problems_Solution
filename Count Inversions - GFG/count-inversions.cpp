// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long count = 0;
    void merge_them(long long arr[], long long left, long long mid, long long right)
    {
        long long int i = left;
        long long int j = mid+1;
        long long int B[right+1];
        long long k = left;
        
        while(i <= mid && j <= right)
        {
            if(arr[i] > arr[j])
            {
                count += mid-i+1;
                B[k++] = arr[j++];
            }
            else
            {
                B[k++] = arr[i++];
            }
        }
        
        while(i <= mid)
        {
            B[k++] = arr[i++];
        }
        while(j <= right)
        {
            B[k++] = arr[j++];
        }
        
        for(int k = left; k <= right; k++)
        {
            arr[k] = B[k];
        }
        
    }
    void merge_Sort(long long arr[], long long left, long long right)
    {
        if(left < right)
        {
            int mid = (left+right)/2;
            merge_Sort(arr,left,mid);
            merge_Sort(arr,mid+1,right);
            
            merge_them(arr,left,mid,right);
            
            return;
        }
    }
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        //int count = 0;
        merge_Sort(arr,0,N-1);
        return count;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends