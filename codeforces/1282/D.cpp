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

ll query(string s)
{

	if(sz(s)==0) assert("size is 0");

	rep(i,0,sz(s))
	{
		if(s[i]=='a' || s[i]=='b' ) continue;
		else assert("wrong;");
	}

	cout<<s<<endl;
	ll x;cin>>x;
	if(x==-1 || x==0) exit(0);
	return x;
}

int solve()
{
	string sa="",sb="";
	rep(i,0,300) sa+='a';
	rep(i,0,300) sb+='b';

	ll na = 300-query(sa);
	ll nb = 300-query(sb);

	string s = "";
	rep(i,0,na+nb) s+='a';

	if(nb==0) query(s);
	else if(na==0)
	{
		rep(i,0,nb) s[i]='b';
		query(s);
	}

	ll last=nb;
	rep(i,0,na+nb)
	{
		s[i] = 'b';
		ll cur = query(s);
		if(cur==last+1) s[i]='a';
		else last--; 
	} 

	return 0;
}

int main()
{
	// auto start = chrono::high_resolution_clock::now();

	// ios_base::sync_with_stdio(false);
	// cin.tie(0);
	// cout.tie(0);

	ll test_cases=1;
	//cin>>test_cases;
	while(test_cases--)
		solve();

	// auto stop = chrono::high_resolution_clock::now();
	// auto duration = chrono::duration_cast<chrono::milliseconds>(stop-start);
	// cout<<"\nduration: "<<(double)duration.count()<<" milliseconds";
}