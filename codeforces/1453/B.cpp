/*input
7
2
1 1
3
-1 0 2
4
99 96 97 95
4
-3 -5 -2 1
6
1 4 3 2 4 1
5
5 0 0 0 5
9
-367741579 319422997 -415264583 -125558838 -300860379 420848004 294512916 -383235489 425814447

*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int T;cin>>T;
	while(T--)
	{
		long long int n;cin>>n;
		vector<long long int> a(n);
		vector<long long int> d(n-1);
		for(long long int i=0;i<n;i++) cin>>a[i];
		long long int sum = 0;
		for(long long int i=0;i<n-1;i++) d[i] = abs(a[i+1]-a[i]),sum+=d[i];
		long long int ans=min(sum-d[0],sum-d[n-2]);


		for(long long int i=0;i<n-2;i++)
		{
			long long int temp = sum - d[i]-d[i+1]+abs(a[i+2]-a[i]);
			ans=min(ans,temp);
		}
		cout<<ans<<"\n";


	}
	return 0;
}
