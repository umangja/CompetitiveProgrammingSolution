/*input
10
10 19 4 1 11 6 1 20 11 13
2 7 17 8 10 3 20 16 10 8
15 9 9 2 20 9 0 15 0 4
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
#define whatis(x)   cout << #x << " is " << x << "\n";
#define graph(n)    adj(n,vector< ll > () )
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll N = 5e5+5;
vi b(N),I(N),r(N);
ll t[3*N];
ll nn,n;

void update(ll p,ll v)
{
	p+=nn;
	for(t[p]=max(v,t[p]);p>>=1;) t[p]=max(t[p<<1],t[p<<1|1]);
}

ll query(ll l,ll rr)//[l,r)
{
	ll ans=-inf;
	for(l+=nn,rr+=nn;l<rr;l>>=1,rr>>=1)
	{
		if(l&1) ans=max(ans,t[l++]);
		if(rr&1) ans=max(ans,t[--rr]);
	}
	return ans;
}
 
 
int solve()
{
	cin>>n;
	rep(i,0,n)	cin>>b[i];
	rep(i,0,n)	cin>>I[i];
	rep(i,0,n)	cin>>r[i];

	nn=2*n+5;

	vi data;
	rep(i,0,n) data.pb(I[i]),data.pb(r[i]);
	sort(data.begin(), data.end());
	data.erase(unique(data.begin(), data.end()),data.end());
	rep(i,0,n)
	{
		I[i]=lbnd(data.begin(), data.end(),I[i])-data.begin()+1;
		r[i]=lbnd(data.begin(), data.end(),r[i])-data.begin()+1;
	}

	vector< pair< ll,pii > > val;
	rep(i,0,n)
		val.pb(mp(b[i],mp(I[i],r[i])));
 
	sort(val.begin(), val.end(),greater< pair< ll,pii > > ());
	ll ans=0;
 	
	// rep(i,0,n) cout<<val[i].F<<" "<<val[i].S.F<<" "<<val[i].S.S<<"\n";
 	
	rep(i,0,n)
	{
		ll j=i;
		while(j<n && val[j].F==val[i].F)
		{		
			if(query(val[j].S.F+1,nn)>val[j].S.S)
				ans++;
			// cout<<query(val[j].S.F+1,nn)<<" "<<val[j].S.S<<"\n";
			j++;	
		}

		j=i;
		while(j<n && val[j].F==val[i].F)
			update(val[j].S.F,val[j].S.S),j++;
		i=j-1;
	}
 
	cout<<ans;
	return 0;
}
 
int main()
{
	auto start = chrono::high_resolution_clock::now();
 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
 
	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();
 
	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}