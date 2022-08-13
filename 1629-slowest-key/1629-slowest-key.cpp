class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
        char ans = keysPressed[0];
        int max_time = releaseTimes[0];
        
        for(int i = 1; i < keysPressed.size(); i++)
        {
            if(releaseTimes[i] - releaseTimes[i-1] == max_time)
            {
                ans = max(ans,keysPressed[i]);
            }
            if(releaseTimes[i] - releaseTimes[i-1] > max_time)
            {
                max_time = releaseTimes[i] - releaseTimes[i-1];
                ans = keysPressed[i];
            }
        }
        return ans;
    }
};