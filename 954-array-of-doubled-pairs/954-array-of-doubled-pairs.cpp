class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int,int> mpp;
        for(int i = 0; i < arr.size(); i++)
        {
            mpp[arr[i]]++;
        }
        sort(arr.begin(),arr.end());
        for(int i = 0; i < arr.size(); i++)
        {
            if(mpp[arr[i]] > 0){
            if(mpp[arr[i]*2] > 0)
            {
                mpp[arr[i]]--;
                mpp[arr[i]*2]--;
            }
            else if(arr[i] % 2 == 0 && mpp[arr[i]/2] > 0)
            {
                mpp[arr[i]]--;
                mpp[arr[i]/2]--;
            }
            else return false;
            }
        }
        
        return true;
    }
};