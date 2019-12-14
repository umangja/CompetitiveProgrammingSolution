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


int solve()
{
	ll n;cin>>n;
	vi p(n);
	ll gf=0,sf=0,bf=0;

	rep(i,0,n) cin>>p[i];
	map<ll,ll> hash;
	ll num=1;
	for(ll i=n-1;i>=0;i--)
	{
		if(hash.find(p[i])==hash.end()) hash[p[i]]=num++; 
		p[i]=hash[p[i]];
	}
	num--;

	vi freq(num+1,0);
	rep(i,0,n) freq[p[i]]++;
	reverse(freq.begin(), freq.end());
	for(ll i=1;i<num+1;i++) freq[i] += freq[i-1];


	ll b=0;
	ll tot=0;
	rep(i,0,num+1) if(freq[i]<=n/2) b=i;
	rep(g,0,num+1)
	{
		if((freq[b]-freq[g])>=2*(freq[g]+1))
		{	
			ll id = lower_bound(freq.begin(), freq.end(),2*freq[g]+1)-freq.begin();
			if(id==num+1) break;
			ll gc = freq[g];
			ll sc = freq[id]-gc;
			ll bc = freq[b]-sc-gc;
			if(gc>0 && sc>0 && bc>0 && gc<sc && gc<bc && (gc+bc+sc) <=n/2 && (gc+bc+sc)>tot) tot = (gc+bc+sc),gf=gc,bf=bc,sf=sc;
		}

	}



	cout<<gf<<" "<<sf<<" "<<bf<<"\n";
	return 0;
}

int main()
{
	auto start = chrono::high_resolution_clock::now();

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll test_cases=1;
	cin>>test_cases;
	while(test_cases--)
		solve();

	auto stop = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}