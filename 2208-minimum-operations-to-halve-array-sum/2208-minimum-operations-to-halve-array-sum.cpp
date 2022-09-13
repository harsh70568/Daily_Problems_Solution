class Solution {
public:
    int halveArray(vector<int>& nums) {
        double curr_sum = 0;
        int count = 0;
        priority_queue<double> pq;
        for(int i = 0; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            curr_sum += nums[i];
        }
        
        double half_sum = curr_sum / 2.0;
        while(curr_sum > half_sum)
        {
            double num = pq.top();
            pq.pop();
            count++;
            pq.push(num/2.0);
            curr_sum += num/2.0;
            curr_sum -= num;
        }
        
        return count;
    }
};