/*input
20 4
6 2 6 8 4 5 5 8 4 1 7 8 0 3 6 1 1 8 3 0

*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	int N,K;cin>>N>>K;
	vector<int> a(N);
	vector<int> cnt(N,0);
	for(int i=0;i<N;i++) cin>>a[i],cnt[a[i]]++;
	sort(a.begin(), a.end());
	
	ll ans  = 0;
	ll left = K;
	for(int x=0;x<=N && left>0;x++)
	{
		if(cnt[x]>=left){
			continue;
		}
		else
		{
			ans+=(ll)(left-cnt[x])*(ll)(x);
			left = cnt[x];
		}
	}

	assert(left==0);
	cout<<ans<<"\n";

	return 0;
}
