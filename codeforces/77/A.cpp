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

map<string,ll> m;
set<pii> likes;
vi a(3);
vi which(7);

vpii ans;


void fun(ll pos)
{
	if(pos==7)
	{
		vi temp(3,0);
		rep(i,0,7) temp[which[i]]++;
		rep(i,0,3) if(temp[i]==0) return ;
		rep(i,0,3) temp[i]=a[i]/temp[i];

		sort(temp.begin(), temp.end());
		ll el = temp[2]-temp[0];
		ll el2=0;
		rep(i,0,3)
		{
			vi tempp;
			rep(j,0,7) if(which[j]==i) tempp.pb(j);
			rep(j,0,sz(tempp)) rep(k,j+1,sz(tempp)){ if(likes.find(mp(tempp[k],tempp[j]))!=likes.end()) el2++; if(likes.find(mp(tempp[j],tempp[k]))!=likes.end()) el2++; }
		}
		// cout<<el2<<" ";
		ans.pb(mp(el,el2));
		return ;

	}

	rep(i,0,3)
	{
		which[pos]=i;
		fun(pos+1);
	} 
	return ;
}

bool cmp(pii p1,pii p2)
{
	if(p1.F!=p2.F) return p1.F<p2.F;
	return p1.S>p2.S; 
}


int solve()
{
	m["Anka"]=0;
	m["Chapay"]=1;
	m["Cleo"]=2;
	m["Troll"]=3;
	m["Dracul"]=4;
	m["Snowy"]=5;
	m["Hexadecimal"]=6;

	ll n;cin>>n;
	rep(i,0,n)
	{
		string s;cin>>s;
		ll x = m[s];
		cin>>s;
		cin>>s;
		ll y=m[s];
		likes.insert(mp(x,y));
	}


	rep(i,0,3) cin>>a[i];

	fun(0);

	sort(ans.begin(), ans.end(),cmp);
	cout<<ans[0].F<<" "<<ans[0].S<<"\n";

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