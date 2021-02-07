/*input

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

void put(set<ll> &s,ll v,ll &ans){
	if(sz(s)==1 && *s.begin()==v ) return; 
	else {		
		s.clear();
		ans++;
		s.insert(v);
	}
}

int solve()
{
	ll n;cin>>n;
	vi a(n);
	rep(i,0,n) cin>>a[i];

	// set<ll> s1,s2;
	ll ans = 0;
	map<ll,ll> last,doubleP;
	for(ll i=0;i<n;i++){
		ll j = i;
		while(j<n && a[j]==a[i]) j++;
		ll len = j-i;

		if(len>=2){
			if( last.find(a[i])==last.end() ||  i-last[a[i]] > 2 || doubleP[a[i]]==0  ) ans+=2;
			else ans++;
			doubleP[a[i]]=1;
		}
		else{
			if( last.find(a[i])==last.end() ||  i-last[a[i]] > 2 || doubleP[a[i]]==0  ) doubleP[a[i]]=0;
			ans++;
		} 
		last[a[i]] = j-1; 
		i = j-1;
	}


	cout<<ans<<"\n";

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