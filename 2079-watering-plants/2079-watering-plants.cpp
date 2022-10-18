class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int store = capacity;
        int steps = 0;
        for(int i = 0; i < plants.size(); i++)
        {
            if(plants[i] > capacity)
            {
                capacity = store;
                steps = steps + 2*i+1;
                capacity -= plants[i];
            }
            else
            {
                capacity -= plants[i];
                steps++;
            }
        }
        return steps;
    }
};