class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> ans;
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i < n-3; i++)
        {
            for(int j = i+1; j < n-2; j++)
            {
                long long req_sum = 1LL*target - nums[i] - nums[j];
                int left = j+1;
                int right = n-1;
                
                while(left < right)
                {
                    vector<int> temp(4);
                    if(nums[left] + nums[right] == req_sum)
                    {
                        temp[0] = nums[i];
                        temp[1] = nums[j];
                        temp[2] = nums[left];
                        temp[3] = nums[right];
                        
                        ans.push_back(temp);
                        while(left < right && temp[2] == nums[left]) left++;
                        while(left && right && temp[3] == nums[right]) right--;
                    }
                    else if(nums[left] + nums[right] < req_sum)
                    {
                        left++;
                    }
                    else
                    {
                        right--;
                    }
                    
                }
                while(i < n-1 && nums[i] == nums[i+1]) i++;
                while(j < n-1 && nums[j] == nums[j+1]) j++;
            }
            
        }
        
        return ans;
    }
};