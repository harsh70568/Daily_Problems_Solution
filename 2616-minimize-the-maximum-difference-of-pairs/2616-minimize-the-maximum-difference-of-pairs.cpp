class Solution {
public: 
bool is_possible(vector<int> &nums, int mid, int p)
{
     int cnt = 0;
     for(int i = 1; i < nums.size(); i++)
     {
         if(nums[i] - nums[i-1] <= mid)
         {
             cnt++;
             i++;
         }
     }
    
     return cnt >= p;
}
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        
        int low = 0;
        int high = nums[nums.size()-1] - nums[0];
        
        int ans = 0;
        while(low <= high)
        {
            int mid = (low + high) >> 1;
            if(is_possible(nums, mid, p))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        return ans;
    }
};