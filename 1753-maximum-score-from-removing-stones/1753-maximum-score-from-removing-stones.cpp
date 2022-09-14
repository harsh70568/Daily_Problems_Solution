class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int count = 0;
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        
        while(pq.size() >= 2)
        {
            int f = pq.top()-1;
            pq.pop();
            int s = pq.top()-1;
            pq.pop();
            if(f != 0) pq.push(f);
            if(s != 0) pq.push(s);
            count++;
        }
        
        return count;
    }
};