// { Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <sstream>
using namespace std;



string maximumFrequency(string s);

int main()
{
    int t;cin>>t;
    cin.ignore();

    for(int i=0;i<t;i++)
    {

        string s;
        getline(cin,s);
        
        
        cout << maximumFrequency(s) << endl;

    }
    return 0;
}
// } Driver Code Ends

#include<bits/stdc++.h>
string maximumFrequency(string s){
        // Complete the function
        unordered_map<string,int> mpp;
        vector<string> str;
        string si = "";
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == ' ')
            {
                str.push_back(si);
                mpp[si]++;
                si = "";
            }
            else
            {
                si += s[i]; 
            }
        }
        str.push_back(si);
        mpp[si]++;
        
        int maxi = -1;
        for(auto it : mpp)
        {
            if(it.second > maxi)
            {
                maxi = it.second;
            }
        }
        
        for(int i = 0; i < str.size(); i++)
        {
            if(mpp[str[i]] == maxi)
            {
                return str[i] + " " + to_string(maxi);
            }
        }
        
        
        
        
}

