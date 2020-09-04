/*input

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T;cin>>T;
	while(T--)
	{
		int a,b;cin>>a>>b;
		int ans=0;
		int d = abs(a-b);
		for(int x=10;x>=1;x--)
		{
			ans+=d/x;
			d%=x;
		}

		cout<<ans<<"\n";
	}
	return 0;
}
