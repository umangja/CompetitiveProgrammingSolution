/*input
7
1 1 2
1 2 3
2 3 3
1 0 0
1 5 1
2 5 0
2 4 0



*/


//assic value of ('0'-'9') is(48 - 57) and (a-z) is (97-122) and (A-Z) is(65-90) and 32 for space
#include<bits/stdc++.h>
using namespace std;
#define ll          long long
#define pb          push_back
#define pii         pair<ll int,ll int>
#define vpii        vector< pii >
#define vi          vector<ll int>
#define vs			vector< string >
#define vvi         vector< vector< ll > >
#define inf			1e18
#define all(it,a)   for(auto it=(a).begin();it!=(a).end();it++) 
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define repr(i,a,b) for(ll int i=a;i>b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define mp          make_pair
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 4e5+5;
const ll L = (ll)ceil(log2(N));
vi weights(N);
vvi nxt(N,vector< ll > (L,0));  // closest valid parent
vvi sum(N,vector< ll > (L,0)); // 

ll query(ll r,ll x)
{
	x-=weights[r];
	ll ans=1;
	for(ll i=L-1;i>=0;i--)
	{
		// cout<<sum[r][i]<<" ";
		if(sum[r][i]<=x)
		{
			ans+=(1<<i);
			x-=sum[r][i];
			r=nxt[r][i];
		}
	}
	// cout<<"\n";

	return ans;
}


int solve()
{
	ll Q;cin>>Q;
	ll last=0,cnt=1;
	weights[0]=inf;
	for(ll i=0;i<L;i++)
		sum[1][i]=inf;
	while(Q--)
	{
		ll t,p,q;cin>>t>>p>>q;
		p^=last;q^=last;
		if(t==1)
		{
			cnt++;
			weights[cnt]=q;
			if(weights[p]>=weights[cnt])
				nxt[cnt][0]=p;
			else
			{
				for(ll i=L-1;i>=0;i--)
					if(weights[nxt[p][i]]<weights[cnt])
						p=nxt[p][i];
				nxt[cnt][0]=nxt[p][0];
			}

			if(nxt[cnt][0]==0)
				sum[cnt][0]=inf;
			else
				sum[cnt][0]=weights[nxt[cnt][0]];

			for(ll i=1;i<L;i++)
			{
				nxt[cnt][i]=nxt[nxt[cnt][i-1]][i-1];
				if(nxt[cnt][i]==0)
					sum[cnt][i]=inf;
				else
					sum[cnt][i]=sum[cnt][i-1]+sum[nxt[cnt][i-1]][i-1];
				// cout<<sum[cnt][i]<<" ";
			}
			// cout<<"\n";

		}
		else
		{
			ll ans;
			// cout<<p<<" "<<q<<"\n";
			if(q<weights[p])
				ans=0;
			else
				ans = query(p,q);
			cout<<ans<<"\n";
			last=ans;
		}
	}
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	//cin>>t;
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}