/*input
asdfasdf
fasd



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

string s,t;
vvi pos(26,vi ());
ll n,m;
ll check(ll mid)
{
	rep(i,0,n-mid+1)
	{
		ll j = i+mid-1;
		string cur;
		rep(k,0,i) cur+=s[k];
		rep(k,j+1,n) cur+=s[k];


		ll k=0;
		j=0;
		while(k<m && j<sz(cur))
		{
			if(t[k]==cur[j]) {k++,j++;}
			else j++;
		}
		// cout<<"\n";
		if(k==m)
			return 1;
	}	

	return 0;
}
int solve()
{
	cin>>s>>t;
	n=sz(s),m=sz(t);
	rep(i,0,n) pos[s[i]-'a'].pb(i);
	ll low=0,high=n;
	while(low<high)
	{
		ll mid = low+(high-low+1)/2;
		if(check(mid)) low=mid;
		else high=mid-1;
	}

	cout<<low<<"\n";

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