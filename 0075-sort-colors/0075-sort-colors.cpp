class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low = 0;
        int mid = 0;
        int high = arr.size()-1;
        
        while(mid <= high)
        {
            switch(arr[mid])
            {
                case 0:
                    swap(arr[mid], arr[low]);
                    low++;
                    mid++;
                    break;
                case 1:
                    mid++;
                    break;
                case 2:
                    swap(arr[mid], arr[high]);
                    high--;
                    break;
            }
        }
    }
};