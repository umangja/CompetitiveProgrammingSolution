/*input
3
1
1
5
1 4 5 9 10
2
3 4

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1;  cin>>T;
	while(T--)
	{
		int n;cin>>n;
		vector<int> a(n);
		vector<int> arr(2*n+1,0);
		for(int i=0;i<n;i++) cin>>a[i],arr[a[i]]=1;
		
		// 10
		int xMax = 0;
		int cnt0 = 0;
		for(int i=2*n;i>0;i--)
		{
			if(!arr[i]) cnt0++;
			else if(cnt0) cnt0--,xMax++;
		}

		// 01
		int yMax = 0;
		cnt0 = 0;
		for(int i=1;i<=2*n;i++)
		{
			if(!arr[i]) cnt0++;
			else if(cnt0) cnt0--,yMax++;
		}

		int xMin = n-yMax;
		cout<< xMax-xMin+1 <<"\n";


	}
	return 0;
}
