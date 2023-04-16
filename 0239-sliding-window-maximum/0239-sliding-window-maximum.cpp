class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        
        vector<int> ans;
        deque<int> dq;
        
        int i = 0;
        int j = 0;
        while(j < n)
        {
            while(!dq.empty() && nums[j] > dq.back())
            {
                dq.pop_back();
            }
            
            dq.push_back(nums[j]);
            
            if(j-i+1 < k)
            {
                j++;
            }
            else if(j-i+1 == k)
            {
                ans.push_back(dq.front());
                
                if(nums[i] == dq.front()) dq.pop_front();
                
                i++;
                j++;
            }
        }
        
        return ans;
    }
};