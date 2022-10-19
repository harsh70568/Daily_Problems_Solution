class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        
        for(int i = 0; i < asteroids.size(); i++)
        {
            int curr_elem = asteroids[i];
            while(!st.empty() && curr_elem < 0 && st.top() > 0)
            {
                if(-1*curr_elem > st.top())
                {
                    st.pop();
                }
                else if(st.top() > -1*curr_elem)
                {
                    curr_elem = 0;
                }
                else if(st.top() == -1*curr_elem)
                {
                   st.pop();
                    curr_elem = 0;
                }
            }
            if(curr_elem != 0) st.push(asteroids[i]);
        }
        
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;

        }
};