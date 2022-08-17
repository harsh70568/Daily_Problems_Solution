class Solution {
public:
    int countGoodSubstrings(string s) {
        int i = 0;
        int j = 0;
        string temp = "";
        int count = 0;
        int k = 0;
        while(j < s.length())
        {
            set<char> st;
            temp += s[j];
            if(j-i+1 < 3)
            {
                j++;
            }
            else if(j-i+1 == 3)
            {
                for(int index = k; index < k+3; index++)
                {
                    st.insert(temp[index]);
                }
                if(st.size() == 3) count++;
                i++;
                j++;
                k++;
            }
        }
        return count;
    }
};