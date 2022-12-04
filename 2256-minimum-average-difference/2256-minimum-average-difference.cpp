class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        
        vector<long long> left(n);
        vector<long long> right(n);
        
        left[0] = nums[0];
        right[n-1] = nums[n-1];
        
        for(int i = 1; i < n; i++)
        {
            left[i] = nums[i] + left[i-1];
        }
        
        for(int i = n-2; i >= 0; i--)
        {
            right[i] = right[i+1] + nums[i];
        }
        
        
        
        for(int i = 0; i < n; i++)
        {
            left[i] = (left[i] / (i+1));
        }
        
        // for(int i = 0; i < n; i++)
        // {
        //     cout<<left[i]<<" ";
        // }
        
        for(int i = 0; i < n-1; i++)
        {
            right[i] = (right[i+1] / (n-i-1));
        }
        right[n-1] = 0;
        
        // for(int i = 0; i < n; i++)
        // {
        //     cout<<right[i]<<" ";
        // }
        
        int mini = INT_MAX;
        int index = -1;
        for(int i = 0; i < n; i++)
        {
            if(abs(left[i] - right[i]) < mini)
            {
                mini = abs(left[i] - right[i]);
                index = i;
            }
        }
        
        return index;
        
        
    }
};