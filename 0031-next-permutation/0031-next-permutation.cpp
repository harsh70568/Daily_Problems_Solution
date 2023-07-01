class Solution {
public:
    void nextPermutation(vector<int>& arr) {
        int n = arr.size();
        int i;
        for(i = n-2; i >= 0; i--) if(arr[i+1] > arr[i]) break;
        
        if(i < 0) reverse(arr.begin(), arr.end());
        else
        {
            int j;
            for(j = n-1; j > i; j--)  if(arr[j] > arr[i]) break;
            
            swap(arr[i], arr[j]);
            sort(arr.begin()+i+1, arr.end());
        }
    }
};