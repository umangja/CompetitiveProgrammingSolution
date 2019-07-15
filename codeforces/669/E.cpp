/*input
10
1 1 1000000000
1 4 1000000000
2 2 1000000000
1 5 1000000000
1 8 1000000000
2 15 1000000000
3 3 1000000000
3 10 1000000000
3 6 1000000000
3 7 1000000000

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

const ll N = 1e5+5;
map<ll,ll> bit[N];
void add(ll tm,ll idx,ll val)
{
	for(;tm<N;tm+=tm&-tm)
		bit[tm][idx]+=val;
}

ll prefix_sum(ll tm,ll idx)
{
	ll s=0;
	for(;tm>0;tm-=tm&-tm)
		s+=bit[tm][idx];
	return s;
}

int solve()
{
	ll n;cin>>n;
	vi q1(n),q2(n),q3(n);
	set<ll> times;
	rep(i,0,n)
	{
		ll a,t,x;cin>>a>>t>>x;
		q1[i]=a;q2[i]=t;q3[i]=x;
		times.insert(t);
	}
	map< ll,ll > m;
	ll cur=1;
	all(it,times)
	{
		m[*it]=cur;
		cur++;
	}
	rep(i,0,n)
	{
		ll a=q1[i],t=m[q2[i]],x=q3[i];
		if(a==1) add(t,x,1);
		if(a==2) add(t,x,-1);
		if(a==3) cout<<prefix_sum(t,x)<<"\n";
	}

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