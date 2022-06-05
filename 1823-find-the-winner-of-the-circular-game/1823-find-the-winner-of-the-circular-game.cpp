class Solution {
public:
    int findTheWinner(int n, int k) {
       queue<int> q;
       for(int i = 1; i <=n; i++)
       {
           q.push(i);
       }
        int count = 0;
        while(q.size() > 1 && count < k)
        {
            count++;
            if(count == k)
            {
                q.pop();
                count = 0;
            }
            else
            {
                q.push(q.front());
                q.pop();
            }
        }
        return q.front();
    }
};