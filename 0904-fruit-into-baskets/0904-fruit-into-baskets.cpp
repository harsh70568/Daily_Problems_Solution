class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int, int> mpp;
        int i = 0;
        int j = 0;
        
        int max_len = 0;
        while(j < fruits.size())
        {
            mpp[fruits[j]]++;
            
            if(mpp.size() <= 2) // having less than 2 distinct fruits
            {
                max_len = max(max_len, j-i+1);
                j++;
            }
            else
            {
                while(mpp.size() > 2)
                {
                    mpp[fruits[i]]--;
                    if(mpp[fruits[i]] == 0) mpp.erase(fruits[i]);
                    i++;
                }
                j++;
            }
        }
        
        return max_len;
    }
};