class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        int j = 0;
        double sum = 0;
        double max_avg = INT_MIN;
        while(j < nums.size())
        {
            sum += nums[j];
            
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                double curr_avg = sum/k;
                max_avg = max(max_avg,curr_avg);
                
                sum -= nums[i];
                i++;
                j++;
            }
        }
        return max_avg;
    }
};