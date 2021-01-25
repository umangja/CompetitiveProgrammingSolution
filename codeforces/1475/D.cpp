/*input
5
5 7
5 3 2 1 4
2 1 1 2 1
1 3
2
1
5 10
2 3 2 3 2
1 2 1 2 1
4 10
5 1 3 4
1 2 1 2
4 5
3 2 1 2
2 1 2 1

*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int n,m;
vector<ll> a,b;

int main()
{
	int T = 1; 
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		a.resize(n);
		b.resize(n);
		for(int i=0;i<n;i++) cin>>a[i];
		for(int i=0;i<n;i++) cin>>b[i];


		vector< vector<ll> > mem(3,vector<ll> (n));
		for(int i=0;i<n;i++) mem[b[i]].push_back(a[i]);
		for(int i=1;i<=2;i++) sort(mem[i].begin(), mem[i].end(),greater<ll> ());

		for(int j=1;j<=2;j++) {
			for(int i=1;i<(int)mem[j].size();i++) mem[j][i] += mem[j][i-1];
		}

		ll ans = 1e6;

		for(int cnt2 = 0; cnt2 < (int)mem[2].size(); cnt2++){
			ll gain = mem[2][cnt2];
			ll cost = 2*cnt2+2;

			ll left = m - gain;
			if(left>0){
				ll idx = lower_bound(mem[1].begin(), mem[1].end(),left) - mem[1].begin();
				if(idx<(int)mem[1].size()){
					cost += (idx+1);
				}
				else cost = 1e6;
			}

			if(cost<ans){
				ans = cost;
			}

		}

		// cout<<ans<<"\n";

		// take only 1s
		ll idx = lower_bound(mem[1].begin(), mem[1].end(),m) - mem[1].begin();
		if(idx<(int)mem[1].size()){
			ans = min(ans,idx+1);
		}

		if(ans > 2*n) ans = -1;
		cout<<ans<<"\n";

	}
	return 0;
}
