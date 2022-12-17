class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long int> st;
        long long int op1 = 0;
        long long int op2 = 0;
        for(int i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "*" || tokens[i] == "-" || tokens[i] == "+" || tokens[i] == "/")
            {
                op2 = st.top();
                st.pop();
                        
                op1 = st.top();
                st.pop();
                
                if(tokens[i] == "*") st.push(op1 * op2);
                if(tokens[i] == "/") st.push(op1 / op2);
                if(tokens[i] == "+") st.push(op1 + op2);
                if(tokens[i] == "-") st.push(op1 - op2);
            }
            else
            {
                st.push(stoi(tokens[i]));
            }
        }
        
        return st.top();
    }
};