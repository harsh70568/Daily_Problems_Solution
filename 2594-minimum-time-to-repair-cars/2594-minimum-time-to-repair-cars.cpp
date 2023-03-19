class Solution {
public:
    bool is_possible(vector<int> &ranks, int cars, long long mid)
    {
        long long cc = 0;
        for(int i = 0; i < ranks.size(); i++)
        {
            cc += sqrt(mid / ranks[i]);
        }
        return cc >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 1;
        long long high = 1e18;
        
        long long ans = -1;
        while(low <= high)
        {
            long long mid = 1LL*((low + high) / 2);
            if(is_possible(ranks, cars, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        
        // if(is_possible(ranks, cars, 200))
        // {
        //     cout<<"harsh"<<endl;
        // }
        
        return ans;
    }
};