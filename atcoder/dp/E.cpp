/*input
6 15
6 5
5 6
6 4
6 6
3 5
7 2
*/
#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
int main()
{
	int N,W;cin>>N>>W;
	vector<pair<int,int>> items(N);
	for(int i=0;i<N;i++) cin>>items[i].F>>items[i].S;

	int maxVal = 1e5+5;
	vector<int> dp1(maxVal,1e9+8);
	vector<int> dp2(maxVal,1e9+8);
	dp2[0]=0; 
	for(int j=0;j<N;j++)
	{
		dp1[0]=0;
		for(int i=1;i<maxVal;i++) if(items[j].S<=i) dp1[i]=min(dp1[i],dp2[i-items[j].S]+items[j].F);
		dp2=dp1;
	} 

	int ans = 0;
	for(int i=1;i<maxVal;i++) if(dp2[i]<=W) ans=i;
	cout<<ans<<"\n";
	return 0;
}
