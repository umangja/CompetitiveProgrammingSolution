/*input
10
-31 -35
8 -36
22 64
5 73
-14 8
18 -58
-41 -85
1 -88
-21 -85
-11 82


*/
#include<bits/stdc++.h>
using namespace std;

int fun(pair<int,int> p1,pair<int,int> p2)
{
	int dy = abs(p2.second - p1.second);
	int dx = abs(p2.first - p1.first);
	// cout<<(dy*1.0/dx*1.0)<<" "<<(dy<=dx && dy>=(-1*dx))<<"\n";
	return  (dy<=dx);

}

int main()
{
	int T = 1; // cin>>T;
	while(T--)
	{
		int n;cin>>n;
		vector<pair<int,int>> p(n);
		for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
		
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				ans+=fun(p[i],p[j]);
			}
		}

		cout<<ans<<"\n";

	}
	return 0;
}
