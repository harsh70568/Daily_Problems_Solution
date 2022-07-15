#include<iostream>
using namespace std;
int main()
 {
	//code
	int t;
	cin >> t;
	while(t--)
	{
	    int N;
	    cin >> N;
	    int arr[N];
	    for(int i = 0; i < N; i++)
	    {
	        cin >> arr[i];
	    }
	    
	    int i = 0;
	    int j = N-1;
	    while(i < j)
	    {
	        swap(arr[i],arr[j]);
	        i++;
	        j--;
	    }
	    
	    for(int i = 0; i < N; i++)
	    {
	        cout<<arr[i] <<" ";
	    }
	    cout<<endl;
	}
	return 0;
}