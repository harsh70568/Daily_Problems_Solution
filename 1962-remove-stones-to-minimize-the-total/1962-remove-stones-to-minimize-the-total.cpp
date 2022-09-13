class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = 0;
        priority_queue<int> pq;
        for(int i = 0; i < piles.size(); i++)
        {
            pq.push(piles[i]);
        }
        
        while(k--)
        {
            int top = (pq.top()+1)/2;
            pq.pop();
            pq.push(top);
        }
        
        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};