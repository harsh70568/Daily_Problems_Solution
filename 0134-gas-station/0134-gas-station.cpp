class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int current_gas = 0;
        int req_gas = 0;
        int index = 0;
        
        for(int i = 0; i < gas.size(); i++)
        {
            current_gas += gas[i] - cost[i];
            
            if(current_gas < 0)
            {
                index = i + 1;
                req_gas += current_gas;
                current_gas = 0;
            }
        }
        //cout<<req_gas<<endl;
        if(current_gas + req_gas >= 0) return index;
        else return -1;
        
    }
};