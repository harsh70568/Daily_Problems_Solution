class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        
        int i = 0;
        int j = 0;
        vector<int> ans;
        while(j < nums.size())
        {
            while(!q.empty() && nums[j] > q.back())
            {
                q.pop_back();
            }
            q.push_back(nums[j]);
            
            if(j-i+1 < k)
            {
                j++;
            }
            else
            {
                ans.push_back(q.front());
                if(q.front() == nums[i]) q.pop_front();
                i++;
                j++;
            }
        }
        
        return ans;
    }
};