class Solution {
public:
    bool canPlaceFlowers(vector<int>& flower, int n) {
        if(flower.size() == 1)
        {
            if(flower[0] == 1)
            {
                return n == 0;
            }
            else
            {
                return n <= 1;
            }
        }
        int cnt = 0;
        for(int i = 0; i < flower.size();)
        {
            if(i == 0)
            {
                if(flower[i] == 0 && flower[i+1] == 0)
                {
                    cnt++;
                    i += 2;
                }
                else
                {
                    i++;
                }
            }
            else if(i == flower.size()-1)
            {
                if(flower[i-1] == 0 && flower[i] == 0) cnt++;
                i++;
            }
            else if(flower[i] == 0)
            {
                if(flower[i-1] == 0 && flower[i+1] == 0)
                {
                    cnt++;
                    i += 2;
                }
                else
                {
                    i++;
                }
            }
            else
            {
                i++;
            }
        }
        //cout<<cnt<<endl;
        return cnt >= n;
    }
};