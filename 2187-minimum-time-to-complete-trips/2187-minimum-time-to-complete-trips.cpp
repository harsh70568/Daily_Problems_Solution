class Solution {
public:
    long long int number_of_trips(vector<int> &time, long long int given_time)
    {
        long long int trips = 0;
        
        for(auto it : time)
        {
            long long int val = it;
            trips += (given_time / val);
        }
        
        return trips;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long int low = 1;
        long long int high = 1e14;
        
        while(low < high)
        {
            long long int mid = (low + high) >> 1;
            
            if(number_of_trips(time, mid) >= totalTrips)
            {
                high = mid;
            }
            else
            {
                low = mid+1;
            }
        }
        
        return low;
    }
};