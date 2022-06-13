class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size() < 3) return ans;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++)
        {
            int new_sum = 0-nums[i];
            int left = i+1;
            int right = nums.size()-1;
            while(left < right)
            {
                if(nums[left] + nums[right] < new_sum)
                {
                    left++;
                }
                else if(nums[left] + nums[right] > new_sum)
                {
                    right--;
                }
                else
                {
                    vector<int> temp(3);
                    temp[0] = nums[i];
                    temp[1] = nums[left];
                    temp[2] = nums[right];
                    ans.push_back(temp);
                    
                    while(left < right && nums[left] == temp[1])
                    {
                        left++;
                    }
                    
                    while(left < right && nums[right] == temp[2])
                    {
                        right--;
                    }
                }
                
            }
            while(i < nums.size()-2 && nums[i] == nums[i+1]) i++;
        }
        return ans;
    }
};