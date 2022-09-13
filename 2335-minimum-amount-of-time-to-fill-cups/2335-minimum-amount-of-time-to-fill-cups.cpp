class Solution {
public:
    int fillCups(vector<int>& amount) {
        priority_queue<int> pq;
        
        for(int i = 0; i < amount.size(); i++)
        {
            if(amount[i] != 0)
            pq.push(amount[i]);
        }
        int count = 0;
        while(pq.size() > 1)
        {
            int f = pq.top()-1;
            pq.pop();
            int s = pq.top()-1;
            pq.pop();
            count++;
            if(f != 0) pq.push(f);
            if(s != 0) pq.push(s);
        }
        int add = pq.empty() ? 0 : pq.top();
        return count + add;
    }
};