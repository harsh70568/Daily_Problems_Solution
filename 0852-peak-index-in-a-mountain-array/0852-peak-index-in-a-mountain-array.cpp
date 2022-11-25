class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int index = -1;
        for(int i = 1; i < arr.size()-1; i++)
        {
            if(arr[i-1] < arr[i] && arr[i+1] < arr[i])
            {
                return i;
            }
            else if(arr[i-1] > arr[i] && arr[i+1] > arr[i])
            {
                return i;
            }
        }
        
        return index;
    }
};