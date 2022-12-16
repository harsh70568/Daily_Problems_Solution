class Solution {
public:
    int minDifference(vector<int>& nums) {
        map<int, int> mpp;
        int n = nums.size();
        int maxi = -1;
        int elem = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            mpp[nums[i]]++;
            if(mpp[nums[i]] > maxi)
            {
                maxi = mpp[nums[i]];
                elem = nums[i];
            }
        }
        
        if(n - maxi <= 3) return 0;
        
        else
        {
            sort(nums.begin(), nums.end());
             int first = nums[n-1] - nums[3];  // kill first 3 elements
            int second = nums[n-4] - nums[0];  // kill last 3 elements
            int third  = nums[n-2] - nums[2]; // kill 2 samllest and 1 biggest element
            int fourth = nums[n-3] - nums[1]; // kill 1 smallest and 2 biggest element;
            
            return min({first, second, third, fourth});
        }
    }
};