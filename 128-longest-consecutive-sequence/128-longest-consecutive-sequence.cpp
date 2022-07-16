class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i++)
        {
            s.insert(nums[i]);
        }
        int longest_streak = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(s.find(nums[i]-1) == s.end())
            {
                int curr_elem = nums[i];
                int curr_streak = 1;
                while(s.find(curr_elem+1) != s.end())
                {
                    curr_streak++;
                    curr_elem++;
                }
                longest_streak = max(longest_streak,curr_streak);
            }
        }
        return longest_streak;
    }
};