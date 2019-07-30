/*input
8 63
1 2 3 4 5 6 7 8
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
#define inf			(ll)1e18
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
 
const ll N=4e5+5;
ll fq[N];
int solve()
{
	ll n,I;cin>>n>>I;
	vi a(n);
	set<ll> st;
	rep(i,0,n)  cin>>a[i],st.insert(a[i]);
	ll count=0;
	map<ll,ll> hash;
	all(it,st)
	{
		hash[*it]=count;
		count++;
	}
 
	rep(i,0,n) a[i]=hash[a[i]],fq[a[i]]++;
	ll no = count;
	ll k_max;
	if((8*I)/n>=60) k_max=inf;
	else	k_max = (ll)pow(2,(8*I)/n);

	// rep(i,0,no) cout<<fq[i]<<" "; 
	ll s=0;
	rep(i,0,min(k_max,no)) s+=fq[i];
	ll ans=s;
	rep(i,k_max,no)
	{
		s = s+fq[i]-fq[i-k_max];
		ans=max(s,ans);
	}
 
	ll ts=0;
	rep(i,0,no) ts+=fq[i];
	cout<<ts-ans<<"\n";
 
 
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