class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int curr_gas = 0;
        int start = 0;
        int req_gas = 0;
        for(int i = 0; i < n; i++)
        {
            curr_gas += (gas[i] - cost[i]);
            if(curr_gas < 0)
            {
                start = i+1;
                req_gas += curr_gas;
                curr_gas = 0;
            }
        }
        if(curr_gas + req_gas >= 0) return start;
        else return -1;
        
        
    }
};