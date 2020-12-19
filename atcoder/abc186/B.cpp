/*input
3 2
4 4
4 4
4 4


*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; // cin>>T;
	while(T--)
	{
		int N,W;cin>>N>>W;
		int ans=0,mn=101;
		for(int i=0;i<N;i++) for(int j=0;j<W;j++) {int x;cin>>x; ans+=x; mn=min(mn,x);}
		cout<<ans-mn*N*W<<"\n";		
	}
	return 0;
}
