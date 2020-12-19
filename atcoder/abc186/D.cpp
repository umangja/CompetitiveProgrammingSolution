/*input
5
31 41 59 26 53

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int T = 1; // cin>>T;
	while(T--)
	{
		int N;cin>>N;
		vector<long long int> a(N);
		for(int i=0;i<N;i++) cin>>a[i];
		sort(a.begin(), a.end());
		vector<long long int> pf(N);
		pf[0]=a[0];
		for(int i=1;i<N;i++) pf[i]=pf[i-1]+a[i];
	
		long long int ans=0;
		for(long long int i=1;i<N;i++) ans+=a[i]*(i) - pf[i-1];
		cout<<ans<<"\n";		
	}
	return 0;
}
