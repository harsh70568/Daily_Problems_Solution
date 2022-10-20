class Solution {
public:
    int countCollisions(string directions) {
        stack<char> st;
        int count = 0;
        
        for(int i = 0; i < directions.length(); i++)
        {
            char current = directions[i];
            if(!st.empty() && current == 'S' && st.top() == 'R')
            {
                count += 1;
                st.pop();
                st.push('S');
            }
            else if(!st.empty() && current == 'L')
            {
                if(st.top() == 'S')
                {
                    count += 1;
                    st.pop();
                    st.push('S');
                    current = 'S';
                }
                if(st.top() == 'R')
                {
                    count += 2;
                    st.pop();
                    st.push('S');
                    current = 'S';
                }
            }
            st.push(current);
        }
        
        while(!st.empty())
        {
            char c = st.top();
            st.pop();
            if(!st.empty() && c == 'S' && st.top() == 'R')
            {
                count += 1;
                st.pop();
                st.push('S');
            }
        }
        
        return count;
    }
};