/*input
8 3
1 1 2 2 1 3 1 1
2 7
1 6
2 7


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
const ll N=2e5+5,N2 = 1e6+5,mod=1e9+9,p = 37;
ll power_p[12],inv_power_p[12];
ll bs,lmo=0,rmo=-1;
vi v(N);
ll freq[N2];
ll ansf=0;
map< ll,ll > m;
vi ans(N);

struct node{
	ll l,r,id;
	node(ll a=0,ll b=0,ll d=0){l=a,r=b,id=d;}
};

ll power(ll x,ll y)
{
	ll ans1=1;
	while(y)
	{
		if(y&1) ans1=(ans1*x)%mod;
		y>>=1;
		x=(x*x)%mod;
	}
	return ans1;
}

bool cmp(struct node &a,struct node &b){
	if(a.l/bs==b.l/bs)
		return b.r>a.r;
	return b.l>a.l;
}

void remove(ll l){
	// cout<<l<<" "<<ansf<<"\n";
	ll el = v[l];
	if(freq[el]>0)
		ansf-=freq[el]*freq[el]*el;
	freq[el]--;
	if(freq[el]>0)
		ansf+=freq[el]*freq[el]*el;
	// cout<<l<<" "<<ansf<<"\n";
}

void add(ll l){
	ll el = v[l];
	if(freq[el]>0)
		ansf-=freq[el]*freq[el]*el;
	freq[el]++;
	ansf+=freq[el]*freq[el]*el;
}

int solve()
{

	rep(i,0,N2)
		freq[i]=0;

	ll n,q;cin>>n>>q;
	bs = 1000;
	rep(i,0,n)
		cin>>v[i];
	vector< struct node > query(q);
	rep(i,0,q)
	{
		ll l,r;
		cin>>l>>r;
		struct node a(l-1,r-1,i);
		query[i]=a;
	}

	sort(query.begin(), query.end(),cmp);
	rep(i,0,q)
	{
		ll l = query[i].l,r=query[i].r,id=query[i].id;

		while(lmo>l)
			add(--lmo);
		while(rmo<r)
			add(++rmo);
		while(lmo<l)
			remove(lmo++);
		while(rmo>r)
			remove(rmo--);
		ans[id] = 	ansf;	
	}

	rep(i,0,q)
		cout<<ans[i]<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll t=1;
	while(t--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}