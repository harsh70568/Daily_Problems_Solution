class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        if(nums.size() < 4) return ans;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-3; i++)
        {
            for(int j = i+1; j < nums.size()-2; j++)
            {
                long long req_sum = 1LL*target - nums[i] - nums[j];
                int low = j+1;
                int high = nums.size()-1;
                
                while(low < high)
                {
                    vector<int> temp(4);
                    if(nums[low] + nums[high] == req_sum)
                    {
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[low];
                        temp[3] = nums[high];
                        ans.push_back(temp);
                        
                        while(low < high && nums[low] == temp[2]) low++;
                        while(low < high && nums[high] == temp[3]) high--;
                    }
                    else if(nums[low] + nums[high] < req_sum)
                    {
                        low++;
                    }
                    else
                    {
                        high--;
                    }
                    
                }
                
                while(i+1 < nums.size() && nums[i] == nums[i+1]) i++;
                while(j+1 < nums.size() && nums[j] == nums[j+1]) j++;
            }
        }
        
        return ans;
    }
};