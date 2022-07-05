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
                int current_elem = nums[i];
                int current_streak = 1;
                while(s.find(current_elem+1) != s.end())
                {
                    current_elem = current_elem+1;
                    current_streak++;
                }
                longest_streak = max(longest_streak,current_streak);
            }
        }
        return longest_streak;
    }
};