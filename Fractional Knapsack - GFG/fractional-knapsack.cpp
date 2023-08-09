//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans = 0.0;
        vector<pair<double, int>> temp;
        for(int i = 0; i < n; i++)
        {
            temp.push_back({(double)arr[i].value / arr[i].weight, arr[i].weight});
        }
        
        sort(temp.begin(), temp.end());
        reverse(temp.begin(), temp.end());
        
        for(int i = 0; i < n; i++)
        {
            if(temp[i].second <= W)
            {
                W -= temp[i].second;
                ans += (temp[i].first*temp[i].second);
            }
            else
            {
                ans += (temp[i].first*W);
                W = 0;
                break;
            }
        }
        return ans;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends