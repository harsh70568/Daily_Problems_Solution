class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        bool flag = false;
        int i;
        for(i = n-2; i >= 0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                flag = true;
                break;
            }
        }
        
        // cout<<i<<endl;
        // cout<<flag<<endl;
        if(flag == false)
        {
            reverse(nums.begin(), nums.end());
        }
        else
        {
            int j;
            for(j = n-1; j > i; j--)
            {
                if(nums[j] > nums[i])
                {
                    break;
                }
            }
            
            //cout<<i<<" "<<j<<endl;
            swap(nums[i], nums[j]);
            sort(nums.begin()+i+1, nums.end());
        }
    }
};