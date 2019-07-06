/*input
5
1 2 3 4 5
6
1 1 4 2
2 3 6
1 1 4 2
1 1 5 2
2 5 10
1 1 5 2

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
const ll N = 5e5+5;
ll n;
vi arr(N),t(2*N);

ll gcd(ll x,ll y){
	if(x<y) swap(x,y);
	return (y==0?x:gcd(y,x%y));
}

void build(){
	rep(i,0,n) t[i+n] = arr[i];
	for(ll i=n-1;i>0;i--) t[i] = __gcd(t[i<<1],t[i<<1|1]); 
}

void modify(ll p,ll v){
	for(t[p+=n]=v;p>>=1;) t[p] = __gcd(t[p<<1],t[p<<1|1]);
}

bool check_vertex(ll l,ll x){
	ll count=0,vertex;
	while(l<n){
		count=0;
		if(t[l<<1]%x!=0) count++,vertex=(l<<1);
		if(t[l<<1|1]%x!=0) count++,vertex=(l<<1|1);
		if(count==0) return true;
		if(count>=2) return false;
		l=vertex;
	}
	return true;
}

bool query(ll l,ll r,ll x){
	ll count=0,vertex=-2;
	for(l+=n,r+=n;l<r;l>>=1,r>>=1)
	{
		if((l&1) && (t[l++]%x)!=0)
		{
			count++;
			vertex=l-1;
		}

		if((r&1) && (t[--r]%x)!=0)
		{
			count++;
			vertex=r;
		}

	}

	if(count==1)
		return check_vertex(vertex,x);

	if(count>=2)
		return false;

	return true;
}

int solve()
{
	cin>>n;
	rep(i,0,n) cin>>arr[i];
	build();
	ll m;cin>>m;while(m--){
		ll q;cin>>q;
		if(q==1)
		{
			ll l,r,x;cin>>l>>r>>x;
			if(query(--l,r,x)) cout<<"YES\n";
			else cout<<"NO\n";
		}
		else
		{
			ll p,v;cin>>p>>v;
			modify(--p,v);
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

	solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}