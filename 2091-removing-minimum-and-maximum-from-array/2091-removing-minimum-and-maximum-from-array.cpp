class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int first = -1;
        int second = -1;
        for(int i = 0; i < n; i++)
        {
           if(nums[i] < mini)
           {
               mini = nums[i];
               first = i+1;
           }
           if(nums[i] > maxi)
           {
               maxi = nums[i];
               second = i+1;
           }
            
        }
        
        
        int f = max(first,second);
        int s = n - min(first,second) + 1;
        int th = min(first,n - first + 1) + min(second,n - second + 1);
        
        return min({f,s,th});
        
        
    }
};