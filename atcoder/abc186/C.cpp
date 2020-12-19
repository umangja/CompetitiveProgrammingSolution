/*input
100000

*/
#include<bits/stdc++.h>
using namespace std;
bool check(int x,int b)
{
	while(x>0)
	{
		int d = x%b;
		if(d==7) return 0;
		x/=b;
	}
	return 1;
}
int main()
{
	int T = 1; // cin>>T;
	while(T--)
	{
		int N;cin>>N;
		int ans=0;
		for(int i=1;i<=N;i++) if(check(i,10) && check(i,8)) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
