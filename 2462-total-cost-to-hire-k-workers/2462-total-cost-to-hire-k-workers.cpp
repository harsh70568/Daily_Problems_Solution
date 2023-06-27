class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int can) {
        int n = costs.size();
        long long ans = 0;
        
        int i = can-1;
        int j = n - can;
        
        if(j <= i)
        {
            priority_queue<int, vector<int>, greater<int>> pq(costs.begin(), costs.end());
            //cout<<"Harsh"<<endl;
            
            while(!pq.empty() && k)
            {
                ans += pq.top();
                pq.pop();
                k--;
            }
            return ans;
        }
        else
        {
            priority_queue<int, vector<int>, greater<int>> f;
            priority_queue<int, vector<int>, greater<int>> b;
            i = 0;
            j = n-1;
            
            while(i < can)
            {
                f.push(costs[i]);
                i++;
            }
            
            while(j >= n - can)
            {
                b.push(costs[j]);
                j--;
            }

            i--;
            j++;
            
            while(i < j && k)
            {
                if(f.top() <= b.top())
                {
                    ans += f.top();
                    f.pop();
                    i++;
                    k--;
                    if(i < j) f.push(costs[i]);
                    else break;
                }
                else
                {
                    ans += b.top();
                    b.pop();
                    k--;
                    j--;
                    if(j > i) b.push(costs[j]);
                    else break;
                }
            }
            
            while(k)
            {
                if(!f.empty() && !b.empty() && f.top() <= b.top())
                {
                    ans += f.top();
                    f.pop();
                    k--;
                }
                else if(!f.empty() && !b.empty() && b.top() < f.top())
                {
                    ans += b.top();
                    b.pop();
                    k--;
                }
                else if(!f.empty())
                {
                    ans += f.top();
                    f.pop();
                    k--;
                }
                else
                {
                    ans += b.top();
                    b.pop();
                    k--;
                }
            }
            return ans;
            
        }
        
    }
};