class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int,int> mpp;
        for(int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
        }
        
        int max_fre = -1;
        int small_el = INT_MAX;
        for(auto it : mpp)
        {
            if(it.first % 2 == 0 && mpp[it.first] > max_fre)
            {
                    small_el = it.first;
                    max_fre = mpp[it.first];
            }
        }
        return small_el == INT_MAX ? -1 : small_el;
    }
};