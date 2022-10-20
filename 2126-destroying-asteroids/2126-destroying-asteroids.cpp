class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        int n = asteroids.size();
        long long sum = mass;
        sort(asteroids.begin(), asteroids.end());
        
        for(int i = 0; i < n; i++)
        {
            if(sum >= asteroids[i])
            {
                sum += asteroids[i];
            }
            else
            {
                return false;
            }
        }
        
        return true;
        
    }
};