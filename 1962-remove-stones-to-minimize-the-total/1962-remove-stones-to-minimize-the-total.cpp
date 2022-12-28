class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq(piles.begin(), piles.end());
        
        while(!pq.empty() && k)
        {
            int top = pq.top();
            pq.pop();
            pq.push((top+1)/2);
            k--;
        }
        
        int sum = 0;
        while(!pq.empty())
        {
            sum += pq.top();
            pq.pop();
        }
        
        return sum;
    }
};