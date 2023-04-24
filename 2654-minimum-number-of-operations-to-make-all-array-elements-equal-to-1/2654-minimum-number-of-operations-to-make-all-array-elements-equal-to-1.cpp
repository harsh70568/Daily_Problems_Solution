class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int mini = 1e9;
        int g = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            g = __gcd(g, nums[i]);
            
            if(g == 1)
            {
                int val = i+1;
                for(int k = i+1; k < n; k++)
                {
                    if(nums[k] != 1) val++;
                }
                int j = i;
                int temp = 0;
                int cnt = 0;
                while(j >= 0)
                {
                    temp = __gcd(temp, nums[j]);
                    if(temp == 1)
                    {
                        val += (cnt - 1);
                        break;
                    }
                    j--;
                    cnt++;
                }
                mini = min(mini, val);
                break;
            }
        }
        
        reverse(nums.begin(), nums.end());
        g = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            g = __gcd(g, nums[i]);
            
            if(g == 1)
            {
                int val = i+1;
                for(int k = i+1; k < n; k++)
                {
                    if(nums[k] != 1) val++;
                }
                int j = i;
                int temp = 0;
                int cnt = 0;
                while(j >= 0)
                {
                    temp = __gcd(temp, nums[j]);
                    if(temp == 1)
                    {
                        val += (cnt - 1);
                        break;
                    }
                    j--;
                    cnt++;
                }
                mini = min(mini, val);
                break;
            }
        }
        
        return mini == 1e9 ? -1 : mini;
    }
};